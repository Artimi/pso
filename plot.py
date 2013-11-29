#!/usr/bin/python
# -*- encoding: utf-8 -*-

import matplotlib
matplotlib.use("Agg")
import numpy as np
import pylab as pl
import json
import sys
import os.path
from matplotlib import animation
def f(x, y):
    return (1 - x / 2 + x ** 5 + y ** 3) * np.exp(-x ** 2 - y ** 2)

def sphere(x, y):
	return x * x + y * y

def rosenbrock(x, y):
	return (1 - x)**2 + 100 (y - x**2)**2

def rastrigin(x, y):
	return x**2 - 10 * np.cos(2 * np.pi * x) + y ** 2 -10 * np.cos(2 * np.pi * y) 

functions = {"sphere" : {"f": sphere, "minimum": [0.0, 0.0]},
 "rosenbrock": {"f": rosenbrock, "minimum": [1.0, 1.0]},
  "rastrigin": {"f": rastrigin, "minimum": [0.0, 0.0]}}

class Plotter(object):
	def __init__(self, d):
		self.d = d
		self.problem = d["problem"]
		self.f = functions[self.problem]["f"]
		self.dimension_min = d["dimension_min"]
		self.dimension_max = d["dimension_max"]
		assert len(self.dimension_max) == len(self.dimension_min) == 2
		self.plot_settings()

	def plot_settings(self):
		n = 100
		x = np.linspace(self.dimension_min[0], self.dimension_max[0], n)
		y = np.linspace(self.dimension_min[1], self.dimension_max[1], n)
		self.X, self.Y = np.meshgrid(x, y)


	def save_imgs(self, path):
		self.path = path
		for i, state in enumerate(self.d["states"]):
			dest_path = os.path.join(self.path, str(i) + ".png")
			self.draw(state, dest_path)

	# def save_gif(self, path):
	# 	fig = pl.figure(dpi=80)
	# 	anim = animation.FuncAnimation(fig, self.animate, frames=len(self.d["states"]), blit=False)
	# 	# anim.save(path, writer="imagemagick", fps=4)
	# 	anim.save(path, writer=animation.FFMpegWriter(), fps=4)

	# def animate(self, state):
	# 	pl.cla()
	# 	pl.xlim(self.X.min(), self.X.max())
	# 	pl.ylim(self.Y.min(), self.Y.max())
	# 	pl.scatter(functions[self.problem]["minimum"][0], functions[self.problem]["minimum"][1], marker="x", c='k')
	# 	pl.imshow(self.f(self.X, self.Y), extent=(self.X.min(), self.X.max(), self.Y.min(), self.Y.max()))
	# 	self.scatter_particles(self.d["states"][state])

	def draw(self, state, dest_path):
		pl.cla()
		pl.xlim(self.X.min(), self.X.max())
		pl.ylim(self.Y.min(), self.Y.max())
		pl.scatter(functions[self.problem]["minimum"][0], functions[self.problem]["minimum"][1], marker="x", c='k')
		pl.imshow(self.f(self.X, self.Y), extent=(self.X.min(), self.X.max(), self.Y.min(), self.Y.max()))
		self.scatter_particles(state)
		pl.savefig(dest_path)

	def scatter_particles(self, state):
		for particle in state["particles"]:
			if particle["id"] == state["best_id"]:
				pl.scatter(particle["x"][0], particle["x"][1], c='y', s=35)
			else:
				pl.scatter(particle["x"][0], particle["x"][1], c='k')


if __name__ == '__main__':
	import argparse
	parser = argparse.ArgumentParser()
	parser.add_argument("json")
	parser.add_argument("path")
	args = parser.parse_args()
	with open(args.json) as fp:
		record = json.load(fp)
	p = Plotter(record)
	p.save_imgs(args.path)
	# p.save_gif(args.path)
