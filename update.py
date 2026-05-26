import os
import matplotlib.pyplot as plt

# =========================
# 설정
# =========================

BOJ_LEVELS = ["Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby", "Unrated"]

BOJ_ROOT = "백준"
PROGRAMMERS_ROOT = "프로그래머스"

README_PATH = "README.md"

ASSETS_DIR = "assets"
BOJ_CHART_PATH = os.path.join(ASSETS_DIR, "boj_stats.png")
PROGRAMMERS_CHART_PATH = os.path.join(ASSETS_DIR, "programmers_stats.png")

START_MARKER = "<!-- STATS_START -->"
END_MARKER = "<!-- STATS_END -->"

# =========================
# 문제 수 카운트
# =========================

def count_problem_dirs(path):
    if not os.path.exists(path):
        return 0

    return len([
        name for name in os.listdir(path)
        if os.path.isdir(os.path.join(path, name))
    ])


def get_boj_stats():
    result = {}

    for level in BOJ_LEVELS:
        path = os.path.join(BOJ_ROOT, level)
        result[level] = count_problem_dirs(path)

    return result


def get_programmers_stats():
    result = {f"Lv{i}": 0 for i in range(6)}

    if not os.path.exists(PROGRAMMERS_ROOT):
        return result

    for level_name in os.listdir(PROGRAMMERS_ROOT):
        level_path = os.path.join(PROGRAMMERS_ROOT, level_name)

        if not os.path.isdir(level_path):
            continue

        if not level_name.isdigit():
            continue

        level = int(level_name)

        if not 0 <= level <= 5:
            continue

        problem_dirs = [
            name for name in os.listdir(level_path)
            if os.path.isdir(os.path.join(level_path, name))
        ]

        result[f"Lv{level}"] += len(problem_dirs)

    return result

# =========================
# 그래프 생성
# =========================

def make_boj_chart(stats):
    labels = []
    values = []
    colors = []

    color_map = {
        "Bronze": "#CD7F32",
        "Silver": "#C0C0C0",
        "Gold": "#FFD700",
        "Platinum": "#58D3F7",
        "Diamond": "#00BFFF",
        "Ruby": "#FF007F",
        "Unrated": "#888888",
    }

    for level, count in stats.items():
        if count > 0:
            labels.append(level)
            values.append(count)
            colors.append(color_map.get(level, "#888888"))

    plt.figure(figsize=(9, 4.5))

    bars = plt.barh(labels, values, color=colors)

    plt.title("Baekjoon Solved Problems", fontsize=16, fontweight="bold")
    plt.xlabel("Solved Count")

    plt.gca().invert_yaxis()

    max_value = max(values)

    for bar in bars:
        width = bar.get_width()

        plt.text(
            width + max_value * 0.02 + 0.1,
            bar.get_y() + bar.get_height() / 2,
            str(int(width)),
            va="center",
            fontsize=11
        )

    plt.tight_layout()
    plt.savefig(
        BOJ_CHART_PATH,
        dpi=300,
        transparent=True,
        bbox_inches="tight"
    )
    plt.close()


def make_programmers_chart(stats):
    labels = []
    values = []
    colors = []

    color_map = {
        "Lv0": "#A0A0A0",
        "Lv1": "#7DD3FC",
        "Lv2": "#60A5FA",
        "Lv3": "#818CF8",
        "Lv4": "#A78BFA",
        "Lv5": "#C084FC",
    }

    for level, count in stats.items():
        if count > 0:
            labels.append(level)
            values.append(count)
            colors.append(color_map.get(level, "#888888"))

    plt.figure(figsize=(9, 4.5))

    bars = plt.barh(labels, values, color=colors)

    plt.title("Programmers Solved Problems", fontsize=16, fontweight="bold")
    plt.xlabel("Solved Count")

    plt.gca().invert_yaxis()

    max_value = max(values)

    for bar in bars:
        width = bar.get_width()

        plt.text(
            width + max_value * 0.02 + 0.1,
            bar.get_y() + bar.get_height() / 2,
            str(int(width)),
            va="center",
            fontsize=11
        )

    plt.tight_layout()
    plt.savefig(
        PROGRAMMERS_CHART_PATH,
        dpi=300,
        transparent=True,
        bbox_inches="tight"
    )
    plt.close()

# =========================
# README 생성
# =========================

def make_readme_block(boj_stats, programmers_stats):
    boj_total = sum(boj_stats.values())
    programmers_total = sum(programmers_stats.values())

    total = boj_total + programmers_total

    return f"""
### 🥇 Baekjoon

<p align="center">
  <img src="{BOJ_CHART_PATH.replace(os.sep, '/')}" width="700"/>
</p>

### 💻 Programmers

<p align="center">
  <img src="{PROGRAMMERS_CHART_PATH.replace(os.sep, '/')}" width="700"/>
</p>

| Platform | Solved |
|---|---:|
| Baekjoon | {boj_total} |
| Programmers | {programmers_total} |
| Total | {total} |
"""


# =========================
# README 업데이트
# =========================

def update_readme(new_block):
    if not os.path.exists(README_PATH):
        raise FileNotFoundError("README.md 파일이 없습니다.")

    with open(README_PATH, "r", encoding="utf-8") as f:
        text = f.read()

    if START_MARKER not in text or END_MARKER not in text:
        print("ERROR: README에 STATS 마커가 없습니다.")
        return

    before = text.split(START_MARKER)[0]
    after = text.split(END_MARKER)[1]

    new_text = before + START_MARKER + "\n" + new_block + "\n" + END_MARKER + after

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(new_text)

# =========================
# 실행
# =========================

def main():
    os.makedirs(ASSETS_DIR, exist_ok=True)

    boj_stats = get_boj_stats()
    programmers_stats = get_programmers_stats()

    make_boj_chart(boj_stats)
    make_programmers_chart(programmers_stats)

    new_block = make_readme_block(boj_stats, programmers_stats)

    update_readme(new_block)

    print("✅ README 업데이트 완료")
    print("✅ 그래프 생성 완료")


if __name__ == "__main__":
    main()
