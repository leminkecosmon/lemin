for i in `seq 1 10000`;
do
	./a.out < maps/big.map | grep "fault" >> test_seg
done
