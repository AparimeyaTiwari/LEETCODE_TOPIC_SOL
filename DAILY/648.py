class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        sent = list(sentence.split(" ")) #converting the sentence into a list
        for i in range(len(dictionary)):
            j = 0
            while(j<len(sent)):
                if(len(sent[j]) >= len(dictionary[i])):
                    if(dictionary[i] == sent[j][0:len(dictionary[i])]):
                        sent[j] = dictionary[i]
                j += 1
        op = ""
        for k in range(len(sent)):
            op += sent[k]
            if(k != len(sent)-1):
                op += " "
        return op

