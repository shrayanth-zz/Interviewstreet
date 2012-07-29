import sys
from collections import defaultdict

replacem = defaultdict(str)
replacem['ab'] = 'c'
replacem['ba'] = 'c'
replacem['ac'] = 'b'
replacem['ca'] = 'b'
replacem['bc'] = 'a'
replacem['cb'] = 'a'

R = set()
for i in range(1, 101):
    R.add('a'*i)
    R.add('b'*i)
    R.add('c'*i)
    
def string_reducer(string):
    y = len(string)
    i = 0
    while i < len(string)-1:
        if string[i] != string[i+1]:
            Q= (string[:i], replacem[string[i:i+2]], string[i+2:])
            num = ''.join(Q)
            if len(num) == 1:
                return 1
            elif num in R:
                y = min(y, len(num))
                i += 1
            else:
                string = num
                i = 0
        else:
            i += 1
    return min(y, len(string))

def main(string):
    if len(set(string)) == 1:
        return len(string)
    return string_reducer(string)

if __name__ == '__main__':
    ln = sys.stdin.readline()
    nums = int(ln.strip())
    strn = []
    for i in range(nums):
        out = sys.stdin.readline()
        strn.append(out.strip())
    for x in strn:
        print "%d" % (main(x),)