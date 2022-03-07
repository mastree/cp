'''
Explanation:
The algorithm that i use is just a heuristic one with several improvements.

The main heuristic is like this. For every title, i work on them independently. For instance, i work on title X, with list of article candidate L. For every article, i count the occurence of word that appear in title X in the article. And then sort the article based on the one with the most occurence.

Improvement 1:
Normalize the count of occurence in article by dividing it with the article length.

Improvement 2:
Make an adjustment into how to compute the count of occurence by considering the position of occurence to give greater value to words that appear earlier.

Improvement 3:
Make a function to consider how uniform the occurence count is distributed amongst all words in title X.
This is basically trying to find a way to normalized the value.

Improvement 4:
Remove common english words from title X to eliminate useless counting that can lead to biases.
'''

import numpy
import json
from operator import itemgetter
import math

EXAMDATA = './data/exam_data1.json'
TESTDATA = './data/test_q.json'
TRAINDATA = './data/train_q.json'
ANSDATA = './data/suggestion.json'

examdata = ''
testdata = ''
traindata = ''
commonwords = ['the', 'be', 'to', 'of', 'and', 'a', 'in', 'that', 'it', 'for', 'not', 'on', 'with', 'as', 'is', 'at', 'by', 'from', 'he', 'she', 'it']
def get_from_id(id):
    n = len(examdata)
    l = 0
    r = n - 1
    while (l < r):
        m = (l + r + 1) // 2
        if (examdata[m][0] <= id):
            l = m
        else:
            r = m - 1
    return examdata[l][1]

def canon(text):
    return text.replace('.', ' ').replace(',', ' ').replace('\n', ' ').lower()

def uniformity(ar):
    rerata = 0
    for elem in ar:
        rerata += elem
    rerata = rerata / len(ar)
    ret = 0
    for elem in ar:
        temp = elem - rerata
        ret += temp * temp
    return math.sqrt(ret)

def shortened(ar):
    ret = ''
    for ch in ar:
        ret += ch[0]
    return ret

def filter_unique(ar):
    temp = {}
    for elem in ar:
        temp[elem] = True
    ret = []
    for elem in ar:
        if (elem in temp):
            ret.append(elem)
    return ret

def process_uniformity(ar, fac):
    cnt = 1000
    for i in range(1, len(ar)):
        cnt = min(cnt, ar[i])
    
    ret = (sum(ar) - uniformity(ar)) / fac
    ret += 10000000 * cnt
    return ret

def calc(title, text):
    factor = len(text)
    title = canon(title)
    text = canon(text)

    titles = title.split()
    titles.insert(0, shortened(titles))
    titles = [elem for elem in titles if elem not in commonwords]
    titles = filter_unique(titles)
    texts = text.split()
    tlen = len(titles)
    retlist = [0 for i in range(tlen)]
    for i in range(tlen):
        elem1 = titles[i]
        skor = 5 * tlen

        j = 0
        for elem2 in texts:
            if (elem1 == elem2):
                retlist[i] += skor - tlen * (j / len(texts)) 
            j += 1

    ret = process_uniformity(retlist, factor)
    return ret

if __name__ == '__main__':
    with open(EXAMDATA, 'r') as data:
        examdata = json.load(data)
    with open(TESTDATA, 'r') as data:
        testdata = json.load(data)
    with open(TRAINDATA, 'r') as data:
        traindata = json.load(data)

    examdata = sorted(examdata, key=itemgetter(0))

    for task in testdata:
        title = get_from_id(task['title_id'])
        candidates = []
        for elem in task['candidates']:
            candidates.append([elem, calc(title, get_from_id(elem))])
        temp = sorted(candidates, key=itemgetter(1), reverse=True)
        res = []
        for elem in temp:
            res.append(elem[0])
        task['candidates'] = res

    with open(ANSDATA, 'w') as wfile:
        json.dump(testdata, wfile, indent=2)
