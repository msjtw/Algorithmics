pos = 50
res = 0

for line in io.lines() do
    count = string.sub(line, 2, -1)
    res = res + count//100
    count = count - (count//100)*100

    if string.sub(line,1,1) == 'L' then
        pos_n = pos - count
    else
        pos_n = pos + count
    end

    if pos ~= 0 and (pos_n < 0 or pos_n > 100) then
        print("rotation ", line)
        res = res + 1
    end

    pos = pos_n % 100

    if pos == 0 then
        print("pointing ", line)
        res = res + 1
    end

end
print(res)
