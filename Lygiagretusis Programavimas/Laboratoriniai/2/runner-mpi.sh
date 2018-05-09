for f in mpi*.exec
do
    for i in 1 2 3
    do
        qsub -N "riskus-$f-$i" -o "v-$f-$i.out" -v exec="$f" jobscript-mpi.sh 
    done
done
for f in 1 2 3 4
do
    for i in 1 2 3
    do
        qsub -N "riskus-$f-$i" -o "v-mpi-p$f.exec-$i.out" -v exec="mpi.exec",np=$f jobscript-mpi-np.sh 
    done
done