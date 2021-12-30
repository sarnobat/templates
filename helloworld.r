#!/usr/bin/Rscript

# this one might be useful too: https://www.rosettacode.org/wiki/Read_a_file_line_by_line#R

d <- as.matrix(read.csv2(file("stdin"), header=FALSE, sep=","))
ca <- commandArgs(trailingOnly=TRUE)
pdf(file=ca[1], width=12, height=6)
data <- d[,1:2]
plot(data, type='n')
lines(d)
dev.off()
