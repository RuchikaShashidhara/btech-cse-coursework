#Principal Component Analysis on GDP dataset  

#Importing the libraries
import numpy as np
import matplotlib.pyplot as plt 
import pandas as pd
from pca import *
import plotly
import plotly.graph_objs as go

GDP_cap=pd.read_csv('GDP_capita_spanish_regions.csv')
x = GDP_cap.iloc[:,1:].values

'''# Feature Scaling
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
x = sc.fit_transform(x) 
'''
#Performing PCA
pca = PCA(n_components=3)
pca.fit(x)
x_prime = pca.transform(x)
x_prime = pd.DataFrame(x_prime)

GDP_cap_3d = pd.DataFrame()
GDP_cap_3d["REGION"] = GDP_cap["REGION"]
GDP_cap_3d['PC1'] = x_prime[0]
GDP_cap_3d['PC2'] = x_prime[1]
GDP_cap_3d['PC3'] = x_prime[2]

#Performing K-Means on the generated dataset 
from sklearn.cluster import KMeans
kmeans = KMeans(n_clusters=3)
clusters = kmeans.fit(x_prime)

GDP_cap_3d['cluster'] = pd.Series(clusters.labels_, index=GDP_cap.index)

# Visualize cluster shapes in 3d.

cluster1=GDP_cap_3d.loc[GDP_cap_3d['cluster'] == 0]
cluster2=GDP_cap_3d.loc[GDP_cap_3d['cluster'] == 1]
cluster3=GDP_cap_3d.loc[GDP_cap_3d['cluster'] == 2]

scatter1 = dict(mode = "markers", name = "Cluster 1", type = "scatter3d",    
x = cluster1.iloc[:,1].values, 
y = cluster1.iloc[:,2].values, 
z = cluster1.iloc[:,3].values,
marker = dict( size=2, color='green')
               )
scatter2 = dict(mode = "markers",name = "Cluster 2",type = "scatter3d",    
x = cluster2.iloc[:,1].values, 
y = cluster2.iloc[:,2].values, 
z = cluster2.iloc[:,3].values,
marker = dict( size=2, color='blue')
              )
scatter3 = dict(mode = "markers",name = "Cluster 3",type = "scatter3d",    
x = cluster3.iloc[:,1].values, 
y = cluster3.iloc[:,2].values, 
z = cluster3.iloc[:,3].values,
marker = dict( size=2, color='red')
)

cluster1 = dict(alphahull = 5, name = "Cluster 1", opacity = .1, type = "mesh3d",    
x = cluster1.iloc[:,1].values, y = cluster1.iloc[:,2].values, z = cluster1.iloc[:,3].values,
color='darkblue', showscale = True)

cluster2 = dict(alphahull = 5,name = "Cluster 2",opacity = .1, type = "mesh3d",    
x = cluster2.iloc[:,1].values, y = cluster2.iloc[:,2].values, z = cluster2.iloc[:,3].values,
color='cyan', showscale = True)

cluster3 = dict( alphahull = 5,name = "Cluster 3",opacity = .1,type = "mesh3d",    
x = cluster3.iloc[:,1].values, y =cluster3.iloc[:,2].values, z = cluster3.iloc[:,3].values,
color='coral', showscale = True)

layout = dict(title = 'Interactive Cluster Shapes in 3D',
              scene = dict( xaxis = dict( zeroline=True ),yaxis = dict( zeroline=True ),
             zaxis = dict( zeroline=True )))

d = dict( data=[scatter1, scatter2, scatter3, cluster1, cluster2, cluster3], 
    layout=layout )
fig = go.Figure(data=d)
# Use py.iplot() for IPython notebook
plotly.offline.iplot(fig, filename='mesh3d_sample')
