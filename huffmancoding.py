
from typing import Counter
from array import array
class node:
    def __init__(self,freq,symbol,left=None,right=None):
        self.freq=freq
        self.symbol=symbol
        self.left=left
        self.right=right
        self.huff=''
def printNodes(node, val=''):
    # huffman code for current node
    newVal = val + str(node.huff)
 
    # if node is not an edge node
    # then traverse inside it
    if(node.left):
        printNodes(node.left, newVal)
    if(node.right):
        printNodes(node.right, newVal)
 
        # if node is edge node then
        # display its huffman code
    if(not node.left and not node.right):
        print(f"{node.symbol} -> {newVal}")
str=input("Enter string: ")
count=Counter(str)
temp=''.join(set('aaabcabccd'))
char=[]
for i in temp:
    char.append(i)
freq=[]
for i in char:
    freq.append(count[i])
nodes= []
for x in range(len(char)):
    nodes.append(node(freq[x], char[x]))
while len(nodes)>1:
    nodes=sorted(nodes,key=lambda x:x.freq)
    left = nodes[0]
    right = nodes[1]
    left.huff=0
    right.huff=1
    newNode = node(left.freq+right.freq, left.symbol+right.symbol, left, right)
    nodes.remove(left)
    nodes.remove(right)
    nodes.append(newNode)
print(char)
print(freq)