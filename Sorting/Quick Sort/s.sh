for ((i = 0; i < 100; i++)); do
    ./generator > in
    ./Simple < in > out1
    ./Good < in > out2
    diff -w out1 out2 || break
    echo "OK!"
done
