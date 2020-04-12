n_in = input().split()
n = int(n_in[0])
k = int(n_in[1])
#iterator 선언
it = k-1
#p라는 리스트 만들어 사람 담기
p = [i for i in range(1, n+1)]
#result라는 리스트에 찾은 사람을 찾은 순서대로 담는다
result = []
while True:
    if len(p) == 0: #사람이 리스트에 없을 때 break
        break
    if it >= len(p)-1: #iterator가 범위 밖일 때 조정
        it %= len(p)
    result.append(p[it]) #결과리스트에 찾은 사람 추가
    del p[it] #찾은 사람 삭제
    it += k-1 #다음 사람으로 넘어간다
print("<"+str(result)[1:-1]+">")
