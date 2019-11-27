def solution(s):
    # Type your solution here
    
	s = s[1:-1]
	reverseString = s[::-1]

	if(s == reverseString):    
	   retVal = "true"
	else:
	   retVal = "false"

	return retVal

#inputString = input()
inputString = "[ymN4SUbPccZVUym8WLmaL7WZngeLmVvarmJZOHp6yfArl4YnbGmIqv74cw51Lv4OSmU4toiz2n9OEpLT3g0H27WoV5aBOYYMOmq5q0cpOwYfqmsmlbv6unoJdcTAccuPqpXv4q9nUNbaJEImEMfi3ufbuuplTjhrrlDiDSCs3cBAslm9pll4KFK851kHkj8a4tO7aJglZ0xUr8AtmK36aF1UZ36yGbvbP8fcT4CBnva3esxLnVGPZT8plWjh853ZhBlj6g5Wuc2I4q4IieWwW6YlOk3MAb3y11AjKJLmOnYgOXBAI1lfVlPj7TmqMdLGDV7qiXnnJqleLnfzei1lrkgHcpsn5Lbm58wp4q0qmPfaMhBu0IPaDGteam3Swm5GKnDML41KowDlvLIbXeZcASB2yUp0EBPV7qslWIUaq9SG5G47Vumlne]"
#inputString = "bog"

solution(inputString)

retVal = solution(inputString)
print(retVal)