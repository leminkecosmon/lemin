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

for i in {1..11}
do
	COUNT=0
	GEN="$(./generator --big)"
	GOAL="$(echo "$GEN" | grep required | uniq | cut -d " " -f8)"
	echo $GOAL
	RES="$(echo "$GEN" | ./lem-in | grep "ants through" | cut -d " " -f8)"
	echo $RES
	DIFF=`expr $GOAL - $RES`
	echo $DIFF
	COUNT=`expr $COUNT + $DIFF`
done
	echo $COUNT
	printf "Disparity between expectation/result with big for 10 different paths : %.3f\n" "bc -l <<< $COUNT / 10"
	
for i in {1..6}
do
	COUNT=0
	GEN="$(./generator --big-superposition)"
	GOAL="$(echo "$GEN" | grep required | uniq | cut -d " " -f8)"
	RES="$(echo "$GEN" | ./lem-in | grep "ants through" | cut -d " " -f8)"
	DIFF=`expr $GOAL - $RES`
	COUNT=`expr $COUNT + $DIFF`
done
	echo $COUNT
	printf "Disparity between expectation/result with big-superposition for 5 different paths : %.3f\n" `expr $COUNT / 5`
