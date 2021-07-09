class Solution:
    def minWindow(self, s: str, t: str) -> str:
        """
        Build the counter
        """
        d = dict(collections. Counter(t))
        formed = 0
        slow = 0
        min_str = None
        min_length = sys.maxsize - 1
        for fast in range(len(s)):
            """
            skip if s[fast] doesn't matter
            """
            ch = s[fast]
            fast += 1
            if ch not in d:
                continue
            """
            use the ch to update d
            """
            d[ch] -= 1
            if d[ch] == 0:
                formed += 1

            """
            If all character are satisfied, then need to move the left pointer
            """
            while formed == len(d) and slow <= fast:
                """
                save the result
                """
                curr_length = fast - slow
                if curr_length < min_length:
                    min_length = curr_length
                    min_str = s[slow:fast]

                """
                update the left boundary
                """
                ch = s[slow]
                slow += 1
                if ch not in d:
                    continue
                d[ch] += 1
                if d[ch] == 1:
                    formed -= 1
        return min_str if min_str is not None else ""