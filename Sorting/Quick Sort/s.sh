for ((i = 0; i < 100; i++)); do
    ./generator > in
    time ./Simple < in > out1
    time ./Good < in > out2
    diff -w out1 out2 || break
    echo "OK!"
done
