import os

# 백준 난이도 
boj_levels = ["Bronze", "Silver", "Gold", "Platinum", "Diamond", "Ruby", "Unrated"]

def count_problems(path):
    if not os.path.exists(path):
        return 0
    return len([
        d for d in os.listdir(path)
        if os.path.isdir(os.path.join(path, d))
    ])

# 백준 카운트
boj_result = {}
for lv in boj_levels:
    path = os.path.join("백준", lv)
    boj_result[lv] = count_problems(path)

# 프로그래머스 카운트 prog_result = {f"Lv{i}": 0 for i in range(6)}
prog_root = "프로그래머스"

if os.path.exists(prog_root):
    for name in os.listdir(prog_root):
        full_path = os.path.join(prog_root, name)

        if not os.path.isdir(full_path):
            continue

        if "/" in name:
            continue  # 
        parts = name.split("/")
        
        if name.isdigit():
            lv = int(name)

            if 0 <= lv <= 5:
                subdirs = [
                    d for d in os.listdir(full_path)
                    if os.path.isdir(os.path.join(full_path, d))
                ]

                if subdirs:
                    prog_result[f"Lv{lv}"] += len(subdirs)
                else:
                    prog_result[f"Lv{lv}"] += 1

# 문자열 생성 
boj_text = "\n".join([f"- {k}: {v}" for k, v in boj_result.items() if v > 0])
prog_text = "\n".join([f"- {k}: {v}" for k, v in prog_result.items() if v > 0])

new_block = f"""### 🥇 Baekjoon
{boj_text}

### 💻 Programmers
{prog_text}
"""

# README 치환 
with open("README.md", "r", encoding="utf-8") as f:
    text = f.read()

start = "<!-- STATS_START -->"
end = "<!-- STATS_END -->"

if start in text and end in text:
    new_text = text.split(start)[0] + start + "\n" + new_block + "\n" + end + text.split(end)[1]
else:
    print("ERROR: STATS 구간 없음")
    new_text = text

with open("README.md", "w", encoding="utf-8") as f:
    f.write(new_text)

print("✅ README 업데이트 완료")
