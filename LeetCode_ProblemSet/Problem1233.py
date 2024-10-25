class Solution:
    def removeSubfolders(self, folder: list[str]) -> list[str]:
        def gen(f: list[str]) -> str:
            ans = ""
            for s in f:
                ans += "/" + s
            return ans
            
        lists: list[list[str]] = []
        folder = sorted(folder, key=lambda f: len(f))

        for f in folder:
            lists.append(f[1:].split("/"))

        ans: list[str] = []
        isSubFolder: list[bool] = [False] * len(folder)

        for i in range(len(lists)):
            if isSubFolder[i]:
                continue
            ans.append(gen(lists[i]))

            for j in range(i + 1, len(lists)):
                if lists[i] == lists[j][: len(lists[i])]:
                    isSubFolder[j] = True

        return ans
