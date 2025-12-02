pos = 50
res = 0

for line in io.lines() do
    count = string.sub(line, 2, -1)
    if string.sub(line,1,1) == 'L' then
        pos = pos - count
    else
        pos = pos + count
    end

    pos = pos % 100

    if pos == 0 then
        print("pointing ", line)
        res = res + 1
    end

end
print(res)

