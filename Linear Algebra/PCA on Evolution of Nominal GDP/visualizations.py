import pandas as pd
import numpy as np
import matplotlib as plt
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
from math import sqrt
import matplotlib as plt
import matplotlib.pyplot as plt
import seaborn as sns 
from sklearn.preprocessing import normalize
from pandas import DataFrame
import warnings
from sklearn.datasets import make_blobs
from sklearn.datasets import make_gaussian_quantiles
from sklearn.datasets import make_classification, make_regression
from sklearn.externals import six
import argparse
import json
import re
import os
import sys
import plotly
import plotly.graph_objs as go
plotly.offline.init_notebook_mode()
warnings.filterwarnings('ignore')
get_ipython().run_line_magic('matplotlib', 'inline')


GDP_cap=pd.read_csv('GDP_capita_spanish_regions.csv')
GDP_cap.set_index('REGION',inplace=True)
GDP_cap.index = GDP_cap.index.astype(str)


GDP_cap.plot(figsize=(30,15), kind='box', legend=True, use_index=True, grid=True)

SIZE = 24
plt.rc('xtick', labelsize=SIZE)    # fontsize of the tick X labels 
plt.rc('ytick', labelsize=SIZE)    # fontsize of the tick Y labels 

plt.xlabel('YEARS', size=30)                        # x title label 
plt.ylabel('PER-CAPITA NOMINAL GDP (€)', size=30)   # y title label 
plt.title('Boxplots, spanish regions distribution of the nominal GDP per capita (€)',
          size=34)    # plot title label   


GDP_cap.transpose().plot(figsize=(30,14), kind='line',legend=True, use_index=True, grid=True)

SIZE = 24
plt.rc('xtick', labelsize=SIZE)    # fontsize of the tick X labels 
plt.rc('ytick', labelsize=SIZE)    # fontsize of the tick Y labels 

plt.xlabel('YEARS', size=30)
plt.ylabel('NOMINAL GDP PER CAPITA - €', size=30)
plt.title('Nominal GDP per capita trend and differences across Spanish regions (€)', size=34)
plt.legend(loc=2, prop={'size': 18}) #legend location and size


GDP_cap_max=GDP_cap.max()
GDP_cap_min=GDP_cap.min()
Max_Min_GDP_cap = pd.concat([GDP_cap_max,GDP_cap_min], axis=1) 
Max_Min_GDP_cap.columns = Max_Min_GDP_cap.columns.astype(str) 
Max_Min_GDP_cap.columns = ['MAX_GDP_cap', 'MIN_GDP_cap'] 


Max_Min_GDP_cap.plot(figsize=(28,14), kind='line',legend=True, use_index=True, grid=True)

SIZE = 24
plt.rc('xtick', labelsize=SIZE)    # fontsize of the tick X labels 
plt.rc('ytick', labelsize=SIZE)    # fontsize of the tick Y labels 

plt.xlabel('YEARS', size=30)
plt.ylabel('NOMINAL GDP PER CAPITA - €', size=30)
plt.legend(loc=2, prop={'size': 28})
plt.title('MAX/MIN regional values of the GDP per capita (Regions of Spain, €)', size=36)


Max_Min_GDP_cap['% min/max']=Max_Min_GDP_cap['MIN_GDP_cap']/Max_Min_GDP_cap['MAX_GDP_cap']


ax1=Max_Min_GDP_cap.drop(['% min/max'], axis=1).plot(figsize=(28,14),kind='bar', use_index=True, grid=True)
ax1.set_xlabel('YEAR',size=30) 
ax1.set_ylabel('NOMINAL GDP PER CAPITA - €', size=30)
ax1.set_title('MIN and MAX values of the nominal GDP per Capita (spanish regions)', size=36)
plt.legend(loc=2, prop={'size': 32}) #legend location and size
plt.show()
