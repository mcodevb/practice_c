num = "75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

str = split.(split(num, "\n"));
A = [parse.(Int64, x) for x in str]

B = copy(A);

for i = 14:-1:1
     for (indx, ~) in enumerate(B[i])
        B[i][indx] = B[i][indx] + max(B[i+1][indx], B[i+1][indx+1]);
     end
end
##


## Euler problem 19
total_days = 365*(2000-1900) + 25
sundays = 6:7:total_days

janfeb = [[1], [32]];
for i in 1902:2000
    if (((i-1)%4) == 0)
        map(x->append!(x, x[end]+366), janfeb)
    else
        map(x->append!(x, x[end]+365), janfeb)
    end
end

others = [[60], [91], [121], [152], [182], [213], [244], [274], [305], [335]];
for i in 1902:2000
    if ((i%4) == 0)
        map(x->append!(x, x[end]+366), others)
    else
        map(x->append!(x, x[end]+365), others)
    end
end

sum(map(x -> length(intersect(sundays,x)), janfeb)) + 
sum(map(x -> length(intersect(sundays,x)), others))

## Alternative
using Dates;
months_starting_sunday = length(findall([dayofweek(Date("$year-$month-01")) 
for year in 1901:2000, month in 1:12] .== 7))
