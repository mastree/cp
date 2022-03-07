# import pandas as pd
import numpy as np
# import sys
# from sklearn.linear_model import LinearRegression

def transpose(mat):
    leni = len(mat)
    lenj = len(mat[0])
    ret = [[0 for i in range(leni)] for j in range(lenj)]
    for i in range(leni):
        for j in range(lenj):
            ret[j][i] = mat[i][j]
    return ret

def mult(mat1, mat2):
    leni = len(mat1)
    lenj = len(mat2[0])
    lenk = len(mat1[0])
    ret = [[0 for i in range(lenj)] for i in range(leni)]

    for i in range(leni):
        for k in range(lenk):
            for j in range(lenj):
                ret[i][j] += mat1[i][k] * mat2[k][j]
    return ret

# if __name__ == '__main__':
#     stepnum = sys.argv[1]
#     csvpath = sys.argv[2]
#     df = pd.read_csv(csvpath);
#     if (stepnum == 'step1'):
#         attr = ['sales', 'temperature', 'THI', 'num_staff']
#         lines = []
#         for elem in attr:
#             line = []
#             line.append(df[elem].mean())
#             line.append(df[elem].var())
#             line.append(df[elem].min())
#             line.append(df[elem].max())
#             lines.append(line)
#         for line in lines:
#             for i in range(4):
#                 print(line[i], end='')
#                 if (i != 3):
#                     print(end=',')
#                 else:
#                     print()
#     else:
#         fillin1 = ['sales', 'temperature', 'THI', 'num_staff']
#         for elem in fillin1:
#             temp = df[elem].mean()
#             df[elem] = df[elem].fillna(temp)
#         df['weather'] = df['weather'].fillna(1)
        
#         for elem in ['temperature', 'THI', 'num_staff']:
#             mn = df[elem].min()
#             mx = df[elem].max()
#             df[elem] = df[elem].map(lambda old: (old - mn) / (mx - mn))
#         df = df.sort_values(by='date')
#         if (stepnum == 'step2'):
#             for idxx, data in df.iterrows():
#                 for i in range(len(data)):
#                     print(data[i], end='')
#                     if (i == len(data) - 1):
#                         print()
#                     else:
#                         print(end=',')
#         else:
#             csvpath2 = sys.argv[3]
#             for i in range(4):
#                 temp = []
#                 for elem in df['weather']:
#                     if (elem == i):
#                         temp.append(1)
#                     else:
#                         temp.append(0)
#                 df['weather' + str(i)] = temp
#             del df['weather']
#             sales = df['sales'].values.tolist()
#             mat = df.iloc[:, 2:].values.tolist()
#             X = np.array(mat)
#             y = np.array(sales)
#             reg = LinearRegression().fit(X, y)

#             df2 = pd.read_csv(csvpath2)
#             fillin2 = ['sales', 'temperature', 'THI', 'num_staff']
#             for elem in fillin2:
#                 temp = df2[elem].mean()
#                 df2[elem] = df2[elem].fillna(temp)
#             df2['weather'] = df2['weather'].fillna(1)
            
#             for elem in ['temperature', 'THI', 'num_staff']:
#                 mn = df2[elem].min()
#                 mx = df2[elem].max()
#                 df2[elem] = df2[elem].map(lambda old: (old - mn) / (mx - mn))
#             for i in range(4):
#                 temp = []
#                 for elem in df2['weather']:
#                     if (elem == i):
#                         temp.append(1)
#                     else:
#                         temp.append(0)
#                 df2['weather' + str(i)] = temp
#             del df2['weather']
#             to_pred = df2.iloc[:, 2:].values.tolist()
#             res = reg.predict(np.array(to_pred))
#             for i in res:
#                 print(i)
