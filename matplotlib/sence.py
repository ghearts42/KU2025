import numpy as np
import matplotlib.pyplot as plt

# 카드 데미지
FullStack = 100
buzzword = 54
callnResponse = 15
callnResponse2 = 34
glass = 13
glass2 = 15

# 집중 스택: 0부터 100까지
focus_stack = np.arange(0, FullStack+1, 1)

# hojo_stack은 focus_stack에 따라 자동으로 결정됨
hojo_stack = FullStack - focus_stack

# 최종 데미지 계산
buzzwordScore = (buzzword + focus_stack) * (1.5 + 0.1 * hojo_stack)
callnResponseScore = ((callnResponse + (focus_stack)) + (callnResponse2 + focus_stack*1.5)) * (1.5 + 0.1 * hojo_stack)
glassScore = (glass + focus_stack) * (1.5 + 0.1 * hojo_stack) + (glass2 + focus_stack) * (1.5 + 0.1 * hojo_stack)

# 그래프 그리기
plt.figure(figsize=(6, 6))
plt.plot(focus_stack, buzzwordScore, color='red',label='bW')
plt.plot(focus_stack, callnResponseScore, color='blue',label='cNR')
plt.plot(focus_stack, glassScore, color='green', label='gS')
plt.legend()

# 라벨 및 제목
plt.xlabel('Focus')
plt.ylabel('Score')
plt.title('Focus + Hojo')
plt.grid(True)
plt.tight_layout()
plt.show()