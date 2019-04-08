package com.Utils;
import android.content.Context;
import android.support.v4.view.ViewPager;
import android.widget.ImageView;
import android.widget.LinearLayout;
 
import java.util.ArrayList;

import com.example.eat.R;
import com.man.activity.gDetailActivity;
import com.man.adapter.TeaNetPageAdapter;
 
/**
 * �ֲ�չʾ������
 * ����: yzp on 2016-09-07.
 * E-mail: 15111424807@163.com
 * QQ: 486492302
 */
public class CarouselShow {
 
  private final Context context;
  private LinearLayout point_group;
  private ArrayList<ImageView> viewpage_imageList;
  protected int lastPosition = 0;
  private ViewPager ViewPage_Detail;
  private LinearLayout point_detail;
 
  public CarouselShow(Context context, ArrayList<ImageView> viewpage_imageList) {
    this.context = context;
    this.viewpage_imageList = viewpage_imageList;
  }
 
  /**
   * ����Ҫ����ֲ����ܵ�ʱ�� ����һ���������� ��ʵ�ִ˷���
   */
  public void CarouselShow_Info_Detail(gDetailActivity view){
 
    ViewPage_Detail = (ViewPager)view.findViewById(R.id.ViewPage_Detail);
    point_detail = (LinearLayout) view.findViewById(R.id.point_detail);
    ViewPage_Detail.setAdapter(new TeaNetPageAdapter(viewpage_imageList));
 
    // ���õ�ǰviewPager��λ��
    ViewPage_Detail.setCurrentItem(Integer.MAX_VALUE / 2
        - (Integer.MAX_VALUE / 2 % viewpage_imageList.size()));
 
    ViewPage_Detail.setOnPageChangeListener(new ViewPager.OnPageChangeListener() {
      @Override
      public void onPageSelected(int position) {
        // ҳ���л�����ã� position���µ�ҳ��λ��
        // ʵ��������ѭ������
        position %= viewpage_imageList.size();
 
        // �ѵ�ǰ������Ϊtrue,����һ������Ϊfalse��������point_groupͼ��
        point_detail.getChildAt(position).setEnabled(true);
        point_detail.getChildAt(position).setBackgroundResource(R.drawable.green_point);//���þ۽�ʱ��ͼ����ʽ
        point_detail.getChildAt(lastPosition).setEnabled(false);
        point_detail.getChildAt(lastPosition).setBackgroundResource(R.drawable.light_green_point);//��һ�Żָ�ԭ��ͼ��
        lastPosition = position;
      }
      @Override
      public void onPageScrolled(int position, float positionOffset, int positionOffsetPixels) {
 
      }
      @Override
      public void onPageScrollStateChanged(int state) {
 
      }
    });
 
  }
}