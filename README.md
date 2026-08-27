import os
import re
from pathlib import Path
from datetime import datetime

import requests


# ============================================================
# CONFIG
# ============================================================

HANDLE = "maheecse"

ROOT = Path(__file__).resolve().parent.parent
README = ROOT / "README.md"

API_URL = "https://codeforces.com/api"


# ============================================================
# CODEFORCES API
# ============================================================

def cf_api(method, params=None):
    url = f"{API_URL}/{method}"

    response = requests.get(
        url,
        params=params or {},
        timeout=20
    )

    response.raise_for_status()

    data = response.json()

    if data["status"] != "OK":
        raise Exception(data.get("comment", "Codeforces API error"))

    return data["result"]


# ============================================================
# GET USER INFORMATION
# ============================================================

def get_user_info():
    users = cf_api(
        "user.info",
        {
            "handles": HANDLE
        }
    )

    return users[0]


# ============================================================
# GET CONTEST HISTORY
# ============================================================

def get_rating_history():
    return cf_api(
        "user.rating",
        {
            "handle": HANDLE
        }
    )


# ============================================================
# GET ACCEPTED SUBMISSIONS
# ============================================================

def get_submissions():
    return cf_api(
        "user.status",
        {
            "handle": HANDLE,
            "from": 1,
            "count": 10000
        }
    )


# ============================================================
# COUNT UNIQUE SOLVED CODEFORCE PROBLEMS
# ============================================================

def count_solved(submissions):

    solved = set()

    for submission in submissions:

        if submission.get("verdict") != "OK":
            continue

        problem = submission.get("problem", {})

        contest_id = problem.get("contestId")
        index = problem.get("index")

        if contest_id is not None and index:
            solved.add(
                f"{contest_id}{index}"
            )

    return solved


# ============================================================
# COUNT REPOSITORY SOLUTIONS
# ============================================================

def get_cpp_files():

    files = []

    ignored = {
        ".git",
        ".github",
        "scripts",
        "__pycache__"
    }

    for path in ROOT.rglob("*.cpp"):

        if any(part in ignored for part in path.parts):
            continue

        files.append(path)

    return files


def count_repo_solutions():

    cpp_files = get_cpp_files()

    return len(cpp_files)


# ============================================================
# FOLDER STATISTICS
# ============================================================

def get_folder_stats():

    folders = [
        "800",
        "900",
        "1000",
        "1100",
        "1200",
        "1300",
        "1400",
        "1500",
        "1600",
        "A_problems_CF",
        "B_problems_CF",
        "C_problems_CF",
        "D_problems_CF",
        "xyz_problems_CF"
    ]

    stats = []

    for folder in folders:

        folder_path = ROOT / folder

        if not folder_path.exists():
            continue

        count = len(
            list(folder_path.rglob("*.cpp"))
        )

        if count > 0:
            stats.append(
                (folder, count)
            )

    return stats


# ============================================================
# RECENT SOLUTIONS
# ============================================================

def get_recent_solutions(limit=10):

    files = get_cpp_files()

    files.sort(
        key=lambda x: x.stat().st_mtime,
        reverse=True
    )

    return files[:limit]


# ============================================================
# CLEAN FILE NAME
# ============================================================

def clean_name(path):

    name = path.stem

    name = name.replace("_", " ")

    return name


# ============================================================
# PROGRESS BAR
# ============================================================

def progress_bar(value, maximum, length=20):

    if maximum == 0:
        return "░" * length

    filled = int(
        (value / maximum) * length
    )

    filled = min(filled, length)

    return (
        "█" * filled +
        "░" * (length - filled)
    )


# ============================================================
# GENERATE README
# ============================================================

def generate_readme(
    user,
    ratings,
    solved,
    repo_count,
    folder_stats,
    recent
):

    rating = user.get("rating", 0)
    max_rating = user.get("maxRating", 0)

    rank = user.get(
        "rank",
        "Unrated"
    )

    max_rank = user.get(
        "maxRank",
        "Unrated"
    )

    contests = len(ratings)

    last_contest_rating = (
        ratings[-1]["newRating"]
        if ratings
        else rating
    )

    solved_count = len(solved)

    updated = datetime.utcnow().strftime(
        "%d %B %Y • %H:%M UTC"
    )

    # --------------------------------------------------------
    # FOLDER TABLE
    # --------------------------------------------------------

    folder_table = ""

    if folder_stats:

        for folder, count in folder_stats:

            folder_table += (
                f"| `{folder}` | "
                f"**{count}** | "
                f"🟢 Active |\n"
            )

    else:

        folder_table = (
            "| No solutions yet | 0 | 🔴 |\n"
        )

    # --------------------------------------------------------
    # RECENT SOLUTIONS
    # --------------------------------------------------------

    recent_table = ""

    for index, path in enumerate(recent, 1):

        relative = path.relative_to(ROOT)

        link = str(relative).replace(
            " ",
            "%20"
        )

        name = clean_name(path)

        recent_table += (
            f"| {index} | "
            f"`{name}` | "
            f"[View Solution](./{link}) |\n"
        )

    if not recent_table:

        recent_table = (
            "| - | No solutions found | - |\n"
        )

    # --------------------------------------------------------
    # DIFFICULTY PROGRESS
    # --------------------------------------------------------

    difficulties = [
        ("800", 800),
        ("900", 900),
        ("1000", 1000),
        ("1100", 1100),
        ("1200", 1200),
        ("1300", 1300),
        ("1400", 1400),
        ("1500", 1500),
    ]

    difficulty_text = ""

    folder_dict = dict(folder_stats)

    max_count = max(
        folder_dict.values(),
        default=1
    )

    for name, _ in difficulties:

        count = folder_dict.get(
            name,
            0
        )

        bar = progress_bar(
            count,
            max_count
        )

        difficulty_text += (
            f"| 🟣 **{name}** | "
            f"`{bar}` | "
            f"**{count}** |\n"
        )

    # --------------------------------------------------------
    # README
    # --------------------------------------------------------

    return f"""# 🚀 Codeforces Solutions

<p align="center">

<img src="https://img.shields.io/badge/Codeforces-{rating}-1F8ACB?style=for-the-badge&logo=codeforces&logoColor=white">

<img src="https://img.shields.io/badge/Solved-{solved_count}-00C853?style=for-the-badge&logo=codeforces&logoColor=white">

<img src="https://img.shields.io/badge/Repo%20Solutions-{repo_count}-8A2BE2?style=for-the-badge&logo=github&logoColor=white">

<img src="https://img.shields.io/badge/Contests-{contests}-FF9800?style=for-the-badge">

</p>

<p align="center">

### 🧑‍💻 @{HANDLE}

**Keep Solving • Keep Learning • Keep Improving**

</p>

---

## 🏆 Codeforces Profile

| 📊 Statistic | 🔥 Value |
|---|---:|
| Current Rating | **{rating}** |
| Max Rating | **{max_rating}** |
| Current Rank | **{rank}** |
| Best Rank | **{max_rank}** |
| Contests Participated | **{contests}** |
| Last Contest Rating | **{last_contest_rating}** |
| Problems Solved | **{solved_count}** |
| Repository Solutions | **{repo_count}** |

---

## 📈 Rating Status

<p align="center">

<img src="https://img.shields.io/badge/Current-{rating}-blue?style=for-the-badge">

<img src="https://img.shields.io/badge/Maximum-{max_rating}-purple?style=for-the-badge">

<img src="https://img.shields.io/badge/Rank-{rank}-orange?style=for-the-badge">

</p>

---

## 🧠 Problem Solving Progress

| Difficulty | Progress | Solved |
|---|---|---:|
{difficulty_text}

---

## 📁 Repository Statistics

| 📂 Folder | 🧩 Solutions | 🚦 Status |
|---|---:|:---:|
{folder_table}

---

## 💻 Recent Solutions

| # | Problem | Solution |
|---:|---|---|
{recent_table}

---

## 🛠️ Languages & Tools

<p align="center">

<img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white">

<img src="https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white">

<img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white">

<img src="https://img.shields.io/badge/VS%20Code-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white">

</p>

---

## 🎯 Goals

- [ ] Reach **1200 Rating**
- [ ] Reach **1300 Rating**
- [ ] Reach **1400 Rating**
- [ ] Solve **500+ Problems**
- [ ] Improve Contest Performance
- [ ] Master Data Structures & Algorithms

---

## 🔥 My CP Philosophy

> **Don't just solve problems. Understand the pattern behind them.**

```text
Think → Code → Submit → Fail → Debug → Learn → Repeat
