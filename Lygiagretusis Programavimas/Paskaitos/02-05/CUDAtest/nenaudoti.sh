#!/bin/bash

###############################################################
#                                                             #
#    Bourne shell script for submitting a serial job to the   #
#    PBS queue using the qsub command.                        #
#                                                             #
###############################################################

#     Remarks: A line beginning with # is a comment.
#	       A line beginning with #PBS is a PBS directive.
#              PBS directives must come first; any directives
#                 after the first executable statement are ignored.
#
   
##########################
#                        #
#   The PBS directives   #
#                        #
##########################

#          Set the name of the job (up to 15 characters, 
#          no blank spaces, start with alphanumeric character)

#PBS -N AB_1

#          By default, the standard output and error streams are sent
#          to files in the current working directory with names:
#              job_name.osequence_number  <-  output stream
#              job_name.esequence_number  <-  error stream
#          where job_name is the name of the job and sequence_number 
#          is the job number assigned when the job is submitted.
#          Use the directives below to change the files to which the
#          standard output and error streams are sent.

#    #PBS -o stdout_file
#    #PBS -e stderr_file

#          The directive below directs that the standard output and
#          error streams are to be merged, intermixed, as standard
#          output. 

#PBS -j oe

#          Specify the maximum cpu and wall clock time.
#          Format:   hhhh:mm:ss   hours:minutes:seconds
#          Be sure to specify a reasonable value here.
#          If the job does not finish by the time reached,
#          the job is terminated.

# SVARBU!!!

#PBS -l walltime=0:10:00

##PBS -l     cput=0:10:00

#          PBS can send informative email messages to you about the
#          status of your job.  Specify a string which consists of
#          either the single character "n" (no mail), or one or more
#          of the characters "a" (send mail when job is aborted),
#          "b" (send mail when job begins), and "e" (send mail when
#          job terminates).  The default is "a" if not specified.
#          You should also specify the email address to which the
#          message should be send via the -M option.

#  #PBS -m ae

#  #PBS -M user_email_address

#          Specify the number of nodes requested and the
#          number of processors per node. 

# NEKEISTI!!! Nuosekliam darbui reikia 1-o procesariaus!

#PBS -l nodes=1:ppn=1


# Skaiciuoti  QUAD mazge 
# #PBS -Wx=NODESET:ONEOF:FEATURE:QUAD

# Skaiciuoti  QUAD mazge ir rezervuoti visa mazga.
# #PBS -Wx=NODESET:ONEOF:FEATURE:QUAD;NACCESSPOLICY:SINGLEJOB

# Skaiciuoti  i7 mazge
# #PBS -Wx=NODESET:ONEOF:FEATURE:I7

# Skaiciuoti  i7 mazge ir rezervuoti visa mazga.
#PBS -Wx=NODESET:ONEOF:FEATURE:I7;NACCESSPOLICY:SINGLEJOB


echo Starting Job:
date
echo
echo Running script on...
hostname
echo

# Leiskite qsub is katalago, kuriame yra vykdomasis failas  (executable)
cd $PBS_O_WORKDIR

# Jusu vykdomojo failo pavadinimas

# export OMP_NUM_THREADS=1

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/export/apps/devel/cuda-5.0.35/lib/

./a.out

echo
echo Job finished:
date


