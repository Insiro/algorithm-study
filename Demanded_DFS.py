List=[
    ["A","C"],["A","D"],["A","B"],
    ["D","C"],["D","F"],["E","A"],
    ["F","E"],["F","B"],["F","D"],
    ["G","D"],["G","J"],["H","G"],["H","I"],
    ["I","G"],["J","I"],["J","F"],["J","K"],["K","F"]
    ]
start=input("input point of start : ").upper()
end=input("input point of end : ").upper()
sets=set()
sets.add(start)
que = list()
que.append(start)
for i in que:
    for data in List:
        if (data[0]==i) and not(len(sets & {data[1]})):
                que.append(data[1])
                sets.add(data[1])
if sets&{end}:
    print("you can go",end=" ")
else: 
    print("you can not go", end=" ")
print(end+", from "+start)
