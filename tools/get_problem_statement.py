"""
Scrapes the problem statements from https://projecteuler.net
Usage:
    /get_problem_statement.py <prob#>   (1 <= prob# <= 556)
"""

from bs4 import BeautifulSoup

from sys import argv

import codecs
import os
from urllib.request import urlopen

def get_problem_statement(prob_num):
    # url for the specified problem
    addr = "https://projecteuler.net/problem="+prob_num
    # scape the website with BeautifulSoup
    soup = BeautifulSoup(urlopen(addr).read(),"lxml")
    # Return the text from the div containing the problem content
    return soup.find_all("div", {"class" : "problem_content"})[0].text

def write_problem_statement(prob_num):
    # absolute path of pybin directory
    pybin_dir = os.path.dirname(__file__)
    # path of new problem's solution directory relative to pybin directory
    rel_prob_path = '../{:03d}'.format(int(prob_num))
    rel_prob_file = rel_prob_path+'/problem_{:03d}'.format(int(prob_num))
    # absolute path of new problem's solution directory
    problem_file = os.path.join(pybin_dir, rel_prob_file)
    # create file (if none exists) in solution directory and write problem
    # statement to it
    with codecs.open(problem_file,'w','utf-8') as output:
        output.write("Problem "+prob_num+"\n")
        output.write(get_problem_statement(prob_num))

if __name__=="__main__":
    write_problem_statement(argv[1]);

## M. Sullivan. June, 2016
