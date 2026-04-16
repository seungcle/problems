import os
import re

# 백준 난이도 (Unrated 포함)
boj_levels = ["Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby", "Unrated"]

# 프로그래머스
prog_levels = ["Lv1", "Lv2", "Lv3", "Lv4", "Lv5"]

def count_problems(path):
    if not os.path.exists(path):
        return 0
    return len([d for d in os.listdir(path) if os.path.isdir(os.path.join(path, d))])

# 백준 카운트
boj_result = {lv: count_problems(f"백준/{lv}") for lv in boj_levels}

# 프로그래머스 카운트
prog_result = {lv: count_problems(f"프로그래머스/{lv}") for lv in prog_levels}

# 문자열 생성
boj_text = "\n".join([f"- {k}: {v}" for k, v in boj_result.items()])
prog_text = "\n".join([f"- {k}: {v}" for k, v in prog_result.items()])

new_block = f"""### 🥇 Baekjoon
{boj_text}

### 💻 Programmers
{prog_text}
"""

# README 치환
with open("README.md", "r", encoding="utf-8") as f:
    text = f.read()

text = re.sub(
    r"<!-- STATS_START -->.*<!-- STATS_END -->",
    f"<!-- STATS_START -->\n{new_block}\n<!-- STATS_END -->",
    text,
    flags=re.S
)

with open("README.md", "w", encoding="utf-8") as f:
    f.write(text)
