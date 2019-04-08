package com.man.adapter;

import java.util.ArrayList;

import android.support.v4.view.PagerAdapter;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

public class TeaNetPageAdapter extends PagerAdapter {

	private ArrayList<ImageView> viewpage_imageList;
	 
	  public TeaNetPageAdapter(ArrayList<ImageView> viewpage_imageList) {
	 
	    this.viewpage_imageList = viewpage_imageList;
	 
	  }
	  // ��Ҫʵ�������ĸ�����
	 
	  @Override
	  public int getCount() {
	    return Integer.MAX_VALUE;
	  }
	 
	  @Override
	  public boolean isViewFromObject(View view, Object object) {
	    // �ж�view��Object��Ӧ�Ƿ��й�����ϵ
	    if (view == object) {
	      return true;
	    } else {
	      return false;
	    }
	  }
	 
	  @Override
	  public Object instantiateItem(ViewGroup container, int position) {
	    // �����Ӧλ���ϵ�view�� container view����������ʵ����viewpage����,
	    // position: viewpager�ϵ�λ��
	    // ��container�������
	    container.addView(viewpage_imageList.get(position % viewpage_imageList.size()));
	 
	    return viewpage_imageList.get(position % viewpage_imageList.size());
	  }
	 
	  @Override
	  public void destroyItem(ViewGroup container, int position, Object object) {
	    // ���ٶ�Ӧλ���ϵ�Object
	    // super.destroyItem(container, position, object);
	    container.removeView((View) object);
	    object = null;
	  }

}
