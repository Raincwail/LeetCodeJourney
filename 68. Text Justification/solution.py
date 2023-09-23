class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        temp = []
        temp_len = 0
        ans = []

        for i in range(len(words)):
            word = words[i]

            if len(temp) + temp_len + len(word) > maxWidth: # Spaces + String lengths + New Word
                s = ""

                if len(temp) - 1 > 0:
                    space_num = (maxWidth - temp_len) // (len(temp) - 1)
                    extra_space = (maxWidth - temp_len) % (len(temp) - 1)

                    for str_part in temp[:-1]:
                        s += str_part + space_num * " "
                        if extra_space > 0:
                            s += " "
                            extra_space -= 1
                
                    s += temp[-1]

                    ans.append(s)
                else:
                    ans.append(temp[0] + (maxWidth - temp_len) * " ")
                    
                temp = []
                temp_len = 0

            temp.append(word)
            temp_len += len(word)

            if i == len(words) - 1:
                s = " ".join(temp) + (maxWidth - temp_len - len(temp) + 1) * " " 

                ans.append(s)


        return ans

test = Solution()

res = test.fullJustify(words=["This", "is", "an", "example", "of", "text", "justification."],
                       maxWidth = 16)

print(res)