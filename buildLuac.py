#!/usr/bin/python
# -*- coding: UTF-8 -*-
import os
import shutil
os.system("cocos luacompile -s src -d srcc  -e  -k 2dxLua -b XXTEA")


def copyFileTree(src,dst ): 
	if os.path.exists(dst):
		print dst+"  delete**** "
		shutil.rmtree(dst)
	else:
		pass
			

	shutil.copytree(src, dst)
	print "copy tree %s -> %s"%( src,dst)
res = "res"
targetRes = "frameworks/runtime-src/proj.android-studio/app/assets/res"
copyFileTree(res,targetRes)

res = "srcc"
targetRes = "frameworks/runtime-src/proj.android-studio/app/assets/srcc"
copyFileTree(res,targetRes)

os.system("pause")