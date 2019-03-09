import MDAnalysis
import MDAnalysis.lib.NeighborSearch as NS
import numpy as np
import sys
import multiprocessing as mp
from time import time

import numpy as np
import matplotlib.pyplot as plt
from math import isnan
import matplotlib.mlab as ml
import seaborn as sns

top  = 'dump.pdb'
traj = 'dump.xtc'
u = MDAnalysis.Universe(top,traj)
n_frames = u.trajectory.n_frames


UNI = u.select_atoms('all')