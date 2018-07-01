n=5
echo $n
for i in `seq 1 10`
do
    echo $n | ./maker > sample.in
    ./beam < sample.in
    # command time -f "%es" ./beam < sample.in
done