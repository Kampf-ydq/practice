package com.man.test;

import java.util.List;

import com.example.eat.R;
import com.man.dao.GoodsDetailDao;
import com.man.entity.GoodsDetail;

import android.test.AndroidTestCase;

public class TestgDetail extends AndroidTestCase {

	public void testAdd(){
		GoodsDetail goodsDetail = new GoodsDetail(null, R.drawable.pyfirst, R.drawable.pytwo, 
				R.drawable.pythree, R.drawable.pyfour, "95", "��Ҳ��һ����ţ�Ƶ��飬ֵ����ȥ�����������˾���Ŷ���ַ��ӽ̻���PYTHON���");
	
		GoodsDetailDao goodsDetailDao = new GoodsDetailDao(getContext());
		goodsDetailDao.insert(goodsDetail);
	}
	
	public void getAll(){
		GoodsDetailDao goodsDetailDao = new GoodsDetailDao(getContext());
		List<GoodsDetail> list = goodsDetailDao.getAll();
		
		if (list != null) {
			System.out.println(list.size());
		}
	}
	
	public void testFind(){
		GoodsDetailDao goodsDetailDao = new GoodsDetailDao(getContext());
		GoodsDetail goodsDetail = goodsDetailDao.find("1");
		System.out.println(goodsDetail);
	}
}
