---
title: Release notes of the 3.3.2 version of `TFEL`, `MFront` and `MTest`
author: Thomas Helfer
date: 21/09/2021
lang: en-EN
numbersections: true
documentclass: article
from: markdown+tex_math_single_backslash
geometry:
  - margin=2cm
papersize: a4
link-citations: true
colorlinks: true
figPrefixTemplate: "$$i$$"
tblPrefixTemplate: "$$i$$"
secPrefixTemplate: "$$i$$"
eqnPrefixTemplate: "($$i$$)"
---

This version was released This version was released on September 21,
2021 along with `TFEL-3.0.9`, `TFEL-3.1.9` and `TFEL-3.2.6` and inherits
from the issues solved in those versions.

# Issues fixed

## Issue #278: Fix reading a map of Data

Empty map were not supported properly in `Data::read_map`.

For more details, see: <https://sourceforge.net/p/tfel/tickets/278/>