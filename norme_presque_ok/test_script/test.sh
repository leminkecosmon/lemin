for i in {1..100}
do
	COUNT=0
	GEN="$(./generator --flow-one)"
	GOAL="$(echo "$GEN" | grep required | uniq | cut -d " " -f8)"
	RES="$(echo "$GEN" | ./lem-in | grep "ants through" | cut -d " " -f8)"
	DIFF=`expr $GOAL - $RES`
	COUNT=`expr $COUNT + $DIFF`
done

	printf "Disparity between expectation/result with flow-one for a 100 different paths : %d\n" `expr $COUNT / 99`

for i in {1..100}
do
	COUNT=0
	GEN="$(./generator --flow-ten)"
	GOAL="$(echo "$GEN" | grep required | uniq | cut -d " " -f8)"
	RES="$(echo "$GEN" | ./lem-in | grep "ants through" | cut -d " " -f8)"
	DIFF=`expr $GOAL - $RES`
	COUNT=`expr $COUNT + $DIFF`
done
	printf "Disparity between expectation/result with flow-ten for a 100 different paths : %d\n" `expr $COUNT / 99`

for i in {1..100}
do
	COUNT=0
	GEN="$(./generator --flow-thousand)"
	GOAL="$(echo "$GEN" | grep required | uniq | cut -d " " -f8)"
	RES="$(echo "$GEN" | ./lem-in | grep "ants through" | cut -d " " -f8)"
	DIFF=`expr $GOAL - $RES`
	COUNT=`expr $COUNT + $DIFF`
done
	printf "Disparity between expectation/result with flow-thousand for a 100 different paths : %d\n" `expr $COUNT / 99`

for i in {1..10}
do
	COUNT=0
	GEN="$(./generator --big-superposition)"
	echo "$GEN" | time ./lem-in | grep lemin
done
