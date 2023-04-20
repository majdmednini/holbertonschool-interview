#!/usr/bin/python3
"""
Given a list of non-negative integers representing the heights of walls
with unit width 1, as if viewing the cross-section of a relief map, calculate
how many square units of water will be retained after it rains.
"""


def rain(walls):
  """
  walls is a list of non-negative integers.
  """
  if not walls or len(walls) < 3:
    return 0
  arrposition = []
  arrvalue = []
  cont = 0

  for it in range(len(walls)):
    if walls[it] > 0:
      arrposition.append(it)
      arrvalue.append(walls[it])
  for item in range(len(arrposition) - 1):
    if arrvalue[item] <= arrvalue[item + 1] and arrposition[item+1] - arrposition[item]>1:
      cont = cont + (
        (arrposition[item + 1] - arrposition[item] - 1) * arrvalue[item])
    else :
      cont = cont + (
        (arrposition[item + 1] - arrposition[item] - 1) * arrvalue[item + 1])
  return(cont)
