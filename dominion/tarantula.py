#!/usr/bin/env python3
import sys

def parseLine(line):
   spltLin = line.split(':')
   if spltLin[0].strip(' ') in ('-','#####'):
      return None
   numCalls, lineNum, line = [x.strip(' ') for x in spltLin]

   return (numCalls, lineNum, line)

def parseFile(data, gcovFile, pF):
   if "TOTAL" not in data.keys():
      data["TOTAL"] = [0, 0]
      data.sync()
   temp = data["TOTAL"]
   temp[pF] += 1
   data["TOTAL"] = temp
   for line in gcovFile:
      result = parseLine(line)
      if result != None:
	 numCalls, lineNum, line = result
	 if lineNum not in data.keys():
	    temp = [0, 0]
	    temp[pF] = 1
	    data[lineNum] = temp
	 else:
	    currentNum = data[lineNum][pF]
	    temp = data[lineNum]
	    temp[pF] += 1
	    data[lineNum] = temp

   data.sync()

def printResults(data, maxLines=10):
   from operator import itemgetter
   results = {}
   for line in data.keys():
      if line != "TOTAL":
	 tp = float(data["TOTAL"][0])
	 tf = float(data["TOTAL"][1])
	 lp = float(data[line][0])
	 lf = float(data[line][1])

	 try:
	    results[line] = 1 - ((lp/tp) / ((lp/tp) +(lf/tf)))
	 except ZeroDivisionError:
	    results[line] = 0

   print([(k, results[k]) for k in sorted(results, key=results.get, reverse=True)][:maxLines])

if __name__ == '__main__':
   from getopt import getopt
   import shelve

   if len(sys.argv) > 1:
      try:
	 arg = getopt(sys.argv[1:], 'radh', ['help'])
      except:
	 print("Invalid command params. Run as '" + sys.argv[0] + " -h' for more information")
	 sys.exit(1)

      if len(arg[0]) > 2:
	 print("Wrong combo of args. Please use 1.")
	 sys.ext(1)

      if arg[0][0][0] == '-r':
	 with shelve.open("gcov_info_db") as db:
	    db.sync()
	    printResults(db)

      if arg[0][0][0] == '-a':
	 if len(arg[1]) < 2:
	    print("Wrong usage of -a. Usage: -a filename pass/fail")
	    sys.exit(1)

	 pF = arg[1][1]
	 if pF.lower() == "pass":
	    pF = 0
	 elif pF.lower() == "fail":
	    pF = 1
	 else:
	    print("Wrong usage of -a. Usage: -a filename pass/fail")
	    sys.exit(1)

	 try:
	    gcovFile = open(arg[1][0], mode='r')
	 except:
	    print("File does not exist")
	    sys.exit(1)

	 with shelve.open("gcov_info_db") as db:
	    parseFile(db, gcovFile, pF)

      elif arg[0][0][0] == '-h' or arg [0][0][0] == '--help':
	 print("...Help Menu......")

      elif arg[0][0][0] == '-d':
	 answer = input("Are you sure you want to delete database? [y/n]")
	 if answer == 'y':
	    with shelve.open("gcov_info_db") as db:
	       for key in db.keys():
		  del db[key]
	 else:
	    print("Exiting")

   else:
      print("Nothing provided correctly. Reading on default")
      with shelve.open("gcov_info_db") as db:
	 printResults(db)
