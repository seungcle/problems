import os

# =========================
# 설정
# =========================

BOJ_LEVELS = ["Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby", "Unrated"]

BOJ_ROOT = "백준"
PROGRAMMERS_ROOT = "프로그래머스"

README_PATH = "README.md"

ASSETS_DIR = "assets"

BOJ_SVG_PATH = os.path.join(ASSETS_DIR, "boj_stats.svg")
PROGRAMMERS_SVG_PATH = os.path.join(ASSETS_DIR, "programmers_stats.svg")

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
# SVG 생성
# =========================

def generate_svg(title, stats, color_map, output_path):
    labels = [k for k, v in stats.items() if v > 0]
    values = [v for v in stats.values() if v > 0]

    if not labels:
        return

    max_value = max(values)

    width = 800
    bar_height = 32
    gap = 18
    top_padding = 70
    left_padding = 150
    right_padding = 80

    height = top_padding + len(labels) * (bar_height + gap) + 40

    svg = []

    svg.append(f'''
<svg width="{width}" height="{height}" viewBox="0 0 {width} {height}"
     xmlns="http://www.w3.org/2000/svg">

<style>
.title {{
    font: bold 28px sans-serif;
    fill: #111827;
}}

.label {{
    font: 18px sans-serif;
    fill: #374151;
}}

.value {{
    font: bold 18px sans-serif;
    fill: #111827;
}}
</style>

<rect width="100%" height="100%" fill="white"/>

<text x="{width/2}" y="40"
      text-anchor="middle"
      class="title">
    {title}
</text>
''')

    y = top_padding

    for label, value in zip(labels, values):
        bar_width = (value / max_value) * 500
        color = color_map.get(label, "#888888")

        svg.append(f'''
<text x="{left_padding - 15}" y="{y + 22}"
      text-anchor="end"
      class="label">
    {label}
</text>

<rect x="{left_padding}"
      y="{y}"
      rx="10"
      ry="10"
      width="{bar_width}"
      height="{bar_height}"
      fill="{color}"/>

<text x="{left_padding + bar_width + 15}"
      y="{y + 22}"
      class="value">
    {value}
</text>
''')

        y += bar_height + gap

    svg.append("</svg>")

    with open(output_path, "w", encoding="utf-8") as f:
        f.write("\n".join(svg))


def make_boj_svg(stats):
    color_map = {
        "Bronze": "#CD7F32",
        "Silver": "#C0C0C0",
        "Gold": "#FFD700",
        "Platinum": "#58D3F7",
        "Diamond": "#00BFFF",
        "Ruby": "#FF007F",
        "Unrated": "#9CA3AF",
    }

    generate_svg(
        title="Baekjoon Solved Problems",
        stats=stats,
        color_map=color_map,
        output_path=BOJ_SVG_PATH
    )


def make_programmers_svg(stats):
    color_map = {
        "Lv0": "#9CA3AF",
        "Lv1": "#7DD3FC",
        "Lv2": "#60A5FA",
        "Lv3": "#818CF8",
        "Lv4": "#A78BFA",
        "Lv5": "#C084FC",
    }

    generate_svg(
        title="Programmers Solved Problems",
        stats=stats,
        color_map=color_map,
        output_path=PROGRAMMERS_SVG_PATH
    )

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
  <img src="{BOJ_SVG_PATH.replace(os.sep, '/')}" width="700"/>
</p>

### 💻 Programmers

<p align="center">
  <img src="{PROGRAMMERS_SVG_PATH.replace(os.sep, '/')}" width="700"/>
</p>

| Category | Count |
|---|---:|
| 🥇 Baekjoon | {boj_total} |
| 💻 Programmers | {programmers_total} |
| 🏆 Total Solved | {total} |
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

    make_boj_svg(boj_stats)
    make_programmers_svg(programmers_stats)

    new_block = make_readme_block(boj_stats, programmers_stats)

    update_readme(new_block)

    print("✅ SVG 그래프 생성 완료")
    print("✅ README 업데이트 완료")


if __name__ == "__main__":
    main()
