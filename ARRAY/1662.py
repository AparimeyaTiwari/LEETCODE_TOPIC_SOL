def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        p1, p2 = 0, 0  # two pointers for each word of both arrays
        i1, i2 = 0, 0  # two character pointers
        while p1 < len(word1) and p2 < len(word2):  # while loop to traverse arrays
            c1 = word1[p1][i1]  # checking equality
            c2 = word2[p2][i2]  # of each character
            if c1 != c2:  # if not equal return false
                return False
            i1 += 1  # going to next character
            i2 += 1  # same
            if i1 == len(
                word1[p1]
            ):  # if word1[ith] checked reset to 0 and go to next word ie p1 -> next
                i1 = 0
                p1 += 1
            if i2 == len(word2[p2]):  # same
                i2 = 0
                p2 += 1

        return p1 == len(word1) and p2 == len(word2)  # if end then crt

        w1 = ""
        w2 = ""
        for i in range(len(word1)):
            w1 += word1[i]
        for j in range(len(word2)):
            w2 += word2[j]
        return w1 == w2  # simply concatinating

        return "".join(word1) == "".join(word2)  # join parts of arr with '' seperator
