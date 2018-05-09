#!/bin/bash

###############################################################
#                                                             #
#   Shell script for submitting a OpenMPI parallel job to the #
#   PBS queue at Vilkas using the qsub command.               #
#                                                             #
###############################################################

#     Remarks: A line beginning with # is a comment.
#              A line beginning with #PBS is a PBS directive.
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

#PBS -N mpi_darbas

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

#    #PBS -l     cput=0:10:00

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
#
# #PBS -q short

# SVARBU!!!

#PBS -l nodes=2:ppn=4


# Skaiciuoti  QUAD mazguose
# #PBS -Wx=NODESET:ONEOF:FEATURE:QUAD

# Skaiciuoti  QUAD mazguose ir rezervuoti visa mazga.
#PBS -Wx=NODESET:ONEOF:FEATURE:QUAD;NACCESSPOLICY:SINGLEJOB

# Skaiciuoti  i7 mazguose
# #PBS -Wx=NODESET:ONEOF:FEATURE:I7

# Skaiciuoti  i7 mazguose ir rezervuoti visa mazga.
# #PBS -Wx=NODESET:ONEOF:FEATURE:I7;NACCESSPOLICY:SINGLEJOB

# Skaiciuoti QUAD ir i7 mazguose
# #PBS -Wx=NODESET:ANYOF:FEATURE:QUAD,I7

echo Starting Job:
date
echo
echo Running script on...
hostname
echo

echo Allocated nodes:
cat $PBS_NODEFILE                                                                                                                   
echo                                                                                                                                

# Leiskite qsub is katalago, kuriame yra vykdomasis failas  (executable)
cd $PBS_O_WORKDIR


# Pakeiskite a.out i Jusu vykdomojo failo pavadinima

mpirun  a.out


echo
echo Job finished:
date

