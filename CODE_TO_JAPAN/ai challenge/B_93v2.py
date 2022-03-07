import numpy
import json
from operator import itemgetter
import filepath as fp
import math

examdata = ''
testdata = ''
traindata = ''
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

def calc(title, text):
    factor = len(text)
    title = canon(title)
    text = canon(text)

    titles = title.split()
    texts = text.split()
    tlen = len(titles)
    retlist = [0 for i in range(tlen)]
    for i in range(tlen):
        elem1 = titles[i]
        skor = 3 * tlen - i 

        j = 0
        for elem2 in texts:
            if (elem1 == elem2):
                retlist[i] += skor - tlen * (j / len(texts)) 
            j += 1

    ret = sum(retlist) - uniformity(retlist)
    return ret / factor

if __name__ == '__main__':
    with open(fp.const.EXAMDATA, 'r') as data:
        examdata = json.load(data)
    with open(fp.const.TESTDATA, 'r') as data:
        testdata = json.load(data)
    with open(fp.const.TRAINDATA, 'r') as data:
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

    with open(fp.const.ANSDATA, 'w') as wfile:
        json.dump(testdata, wfile, indent=2)
