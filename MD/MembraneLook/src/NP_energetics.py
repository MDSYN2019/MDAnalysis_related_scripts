# E_{edge} = 2 \times sigma \times L \sqrt(L - (LC/2)^2)

import numpy as np
import matplotlib.pyplot as plt
import scipy

"""
From thesis:

gamma values - near the domain boundaries, represent 1.0-7.0 x 10^-10 N  (line tension) 

kappa values = 5.4 K_{B}T for C12E2 

"""
class curvatureEnergetics:
	def __self__(self, L, C, Csp, sigma, A, kappa):
		self.smallCapA = 15.68 # units nm^{2}
		self.middleCapA = 
		self.L = L # Radii?
		self.C = C # Curvature 
		self.Csp = Csp # Spontaneous Curvature
		self.A = A  # Area 
		self.sigma = 1.0*(10**-10) # Need to plot a phase diagram as a function of the line tension  
		self.kappa = 5.4 * 1.38 * (10**(-23)) * 303 # Bilayer Rigidity 
	def define_invagination_length(self):
		self.weird = self.kappa/self.sigma # from the back of the envelope calculation, we can compute as 2.2579559999999998e-10 m which is 0.225 nm  or 2.25 angstroms
	def E_edge(self):
		"""
		Equation from reference - 
		"""
		E = (2 * self.sigma * np.pi * self.L) * np.sqrt(1 - (np.pow((self.L * self.C)/2),2))
		return E
	def E_bend(self):
		"""
		Equation from reference - 
		"""
		E = (0.5 * self.A * self.kappa) * np.pow(((self.L * self.C) - (self.L*self.Csp)), 2)
		return E
	def budding_domain_tension(self):
		
	
	
