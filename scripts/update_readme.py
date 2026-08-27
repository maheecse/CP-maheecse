````python
import requests
from pathlib import Path
from datetime import datetime, timezone


# ============================================================
# CONFIGURATION
# ============================================================

HANDLE = "maheecse"

ROOT = Path(__file__).resolve().parent.parent
README = ROOT / "README.md"

CF_API = "https://codeforces.com/api"


# ============================================================
# CODEFORCES API
# ============================================================

def cf_api(method, params=None):
    url = f"{CF_API}/{method}"

    response = requests.get(
        url,
        params=params or {},
        timeout=30
    )

    response.raise_for_status()

    data = response.json()

    if data["status"] != "OK":
        raise RuntimeError(
            data.get("comment", "Codeforces API error")
        )

    return data["result"]


# ============================================================
# USER INFORMATION
# ============================================================

def get_user():

    result = cf_api(
        "user.info",
        {"handles": HANDLE}
    )

    return result[0]


# ============================================================
# RATING HISTORY
# ============================================================

def get_rating_history():

    return cf_api(
        "user.rating",
        {"handle": HANDLE}
    )


# ============================================================
# ACCEPTED PROBLEMS
# ============================================================

def get_solved_problems():

    submissions = cf_api(
        "user.status",
        {
            "handle": HANDLE,
            "from": 1,
            "count": 10000
        }
    )

    solved = set()

    for submission in submissions:

        if submission.get("verdict") != "OK":
            continue

        problem = submission.get("problem", {})

        contest_id = problem.get("contestId")
        index = problem.get("index")

        if contest_id and index:

            solved.add(
                f"{contest_id}{index}"
            )

    return solved


# ============================================================
# REPOSITORY SOLUTIONS
# ============================================================

def get_cpp_files():

    ignored = {
        ".git",
        ".github",
        "scripts",
        "__pycache__"
    }

    files = []

    for file in ROOT.rglob("*.cpp"):

        if any(
            part in ignored
            for part in file.parts
        ):
            continue

        files.append(file)

    return files


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

        path = ROOT / folder

        if not path.exists():
            continue

        count = len(
            list(path.rglob("*.cpp"))
        )

        if count > 0:
            stats.append(
                (folder, count)
            )

    return stats


# ============================================================
# RECENT SOLUTIONS
# ============================================================

def get_recent_solutions(limit=8):

    files = get_cpp_files()

    files.sort(
        key=lambda x: x.stat().st_mtime,
        reverse=True
    )

    return files[:limit]


# ============================================================
# PROGRESS BAR
# ============================================================

def progress_bar(
    value,
    maximum,
    length=18
):

    if maximum <= 0:
        return "░" * length

    filled = int(
        value / maximum * length
    )

    filled = min(
        filled,
        length
    )

    return (
        "█" * filled +
        "░" * (length - filled)
    )


# ============================================================
# GENERATE FOLDER TABLE
# ============================================================

def make_folder_table(stats):

    if not stats:

        return (
            "| No solutions | 0 | 🔴 |\n"
        )

    result = ""

    for folder, count in stats:

        if folder.isdigit():

            icon = "🟣"

        elif folder.startswith("A_"):

            icon = "🟢"

        elif folder.startswith("B_"):

            icon = "🟡"

        elif folder.startswith("C_"):

            icon = "🟠"

        elif folder.startswith("D_"):

            icon = "🔴"

        else:

            icon = "🔵"

        result += (
            f"| {icon} `{folder}` | "
            f"**{count}** | 🟢 Active |\n"
        )

    return result


# ============================================================
# GENERATE DIFFICULTY TABLE
# ============================================================

def make_difficulty_table(stats):

    data = dict(stats)

    difficulty_folders = [
        "800",
        "900",
        "1000",
        "1100",
        "1200",
        "1300",
        "1400",
        "1500",
        "1600"
    ]

    maximum = max(
        [data.get(x, 0) for x in difficulty_folders],
        default=1
    )

    result = ""

    for difficulty in difficulty_folders:

        count = data.get(
            difficulty,
            0
        )

        bar = progress_bar(
            count,
            maximum
        )

        result += (
            f"| **{difficulty}** | "
            f"`{bar}` | "
            f"**{count}** |\n"
        )

    return result


# ============================================================
# GENERATE RECENT SOLUTIONS
# ============================================================

def make_recent_table(files):

    if not files:

        return (
            "| - | No solutions found | - |\n"
        )

    result = ""

    for number, file in enumerate(
        files,
        start=1
    ):

        relative = file.relative_to(ROOT)

        link = str(relative).replace(
            " ",
            "%20"
        )

        name = file.stem.replace(
            "_",
            " "
        )

        result += (
            f"| {number} | "
            f"`{name}` | "
            f"[View Solution](./{link}) |\n"
        )

    return result


# ============================================================
# GENERATE README
# ============================================================

def generate_readme(
    user,
    ratings,
    solved,
    repo_files,
    folder_stats,
    recent
):

    rating = user.get(
        "rating",
        0
    )

    max_rating = user.get(
        "maxRating",
        0
    )

    rank = user.get(
        "rank",
        "Unrated"
    )

    max_rank = user.get(
        "maxRank",
        "Unrated"
    )

    contests = len(ratings)

    repo_count = len(
        repo_files
    )

    solved_count = len(
        solved
    )

    last_contest_rating = (
        ratings[-1]["newRating"]
        if ratings
        else rating
    )

    now = datetime.now(
        timezone.utc
    ).strftime(
        "%d %B %Y • %H:%M UTC"
    )

    folder_table = make_folder_table(
        folder_stats
    )

    difficulty_table = make_difficulty_table(
        folder_stats
    )

    recent_table = make_recent_table(
        recent
    )

    return f"""# 🚀 Codeforces Solutions

<p align="center">

<img src="https://img.shields.io/badge/Codeforces-{rating}-1F8ACB?style=for-the-badge&logo=codeforces&logoColor=white">

<img src="https://img.shields.io/badge/Max%20Rating-{max_rating}-8A2BE2?style=for-the-badge">

<img src="https://img.shields.io/badge/Problems%20Solved-{solved_count}-00C853?style=for-the-badge">

<img src="https://img.shields.io/badge/Repo%20Solutions-{repo_count}-FF9800?style=for-the-badge">

</p>

<p align="center">

### 👨‍💻 @{HANDLE}

**Competitive Programming • Problem Solving • C++**

</p>

---

## 🏆 Codeforces Profile

| 📊 Statistic | 🔥 Value |
|---|---:|
| Current Rating | **{rating}** |
| Maximum Rating | **{max_rating}** |
| Current Rank | **{rank}** |
| Best Rank | **{max_rank}** |
| Contests | **{contests}** |
| Last Contest Rating | **{last_contest_rating}** |
| Accepted Problems | **{solved_count}** |

---

## 📈 Problem Solving Progress

| Difficulty | Progress | Solved |
|---|---|---:|
{difficulty_table}

---

## 📁 Repository Statistics

| 📂 Folder | 🧩 Solutions | 🚦 Status |
|---|---:|:---:|
{folder_table}

---

## ⚡ Recent Solutions

| # | Problem | Solution |
|---:|---|---|
{recent_table}

---

## 🛠️ Tech Stack

<p align="center">

<img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white">

<img src="https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white">

<img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white">

<img src="https://img.shields.io/badge/VS%20Code-007ACC?style=for-the-badge&logo=visualstudiocode&logoColor=white">

</p>

---

## 🎯 Goals

- [ ] 🟢 Reach 1200 Rating
- [ ] 🟡 Reach 1300 Rating
- [ ] 🟠 Reach 1400 Rating
- [ ] 🔴 Reach 1500 Rating
- [ ] ⭐ Solve 500+ Problems
- [ ] 🏆 Improve Contest Performance
- [ ] 🧠 Master Data Structures & Algorithms

---

## 🔥 CP Mindset

```text
Think
  ↓
Understand
  ↓
Find Pattern
  ↓
Code
  ↓
Submit
  ↓
Debug
  ↓
Learn
  ↓
Repeat
````

> **One problem at a time. One step closer every day.**

---

<p align="center">

⚡ <b>Keep Coding. Keep Improving.</b> ⚡

<br><br>

<i>Last Updated: {now}</i>

</p>
```
