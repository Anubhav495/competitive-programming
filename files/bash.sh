for((i=1;;i++));do
	echo $i
	./gen $i > in
	./A < in > out1
	./cmp < in > out2
	diff -w out1 out2 || break
done
	
