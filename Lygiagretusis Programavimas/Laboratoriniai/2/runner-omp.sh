for f in omp*.exec
do
    for i in 1 2 3
    do
        qsub -N "riskus-$f-$i" -o "v-$f-$i.out" -v exec="$f" jobscript-omp.sh 
    done
done