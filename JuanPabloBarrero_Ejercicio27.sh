#!/bin/bash
#PBS -l nodes=1:ppn=1, mem=1gb,walltime=00:05:00
#PBS -M jp.barrero10@uniandes.edu.co
#PBS -m abe
#PBS -N JuanPabloBarrero_Ejercicio27

cd /hpcfs/home/fisi4028/jp.barrero10/JuanPabloBarrero_Ejercicio27/

module load mpich/3.2.1

make clean
make output1
make output2
