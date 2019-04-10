package com.man.activity;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

import com.Utils.CarouselShow;
import com.example.eat.R;
import com.man.dao.GoodsDetailDao;
import com.man.entity.GoodsDetail;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.v4.view.ViewPager;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

public class gDetailActivity extends Activity {

	  private ViewPager ViewPage_Detail;
	  private LinearLayout point_detail;
	  private Context context;
	  private View view;
	  //�ֲ�ͼͼƬ��Դ
	  private ArrayList<ImageView> viewpage_imageList;
	  //�ж��Ƿ��Զ�����ViewPage
	  private boolean isRunning = true;
	  
	  
	  private TextView score;
	  private TextView goodsIntr;
	  private TextView subOrder;
	  
	  private String goodsId;
	  private String goodsName;
	  private double goodsPrice;
	  private int goodsStore;
	  private String stuId;
	 
	  @Override
	  protected void onCreate(Bundle savedInstanceState) {
	    super.onCreate(savedInstanceState);
	    
	    requestWindowFeature(Window.FEATURE_NO_TITLE);
	    
	    setContentView(R.layout.carousel);
	    
	    //��ʼ���ؼ�
	    ViewPage_Detail = (ViewPager)findViewById(R.id.ViewPage_Detail);
	    point_detail = (LinearLayout)findViewById(R.id.point_detail);
	    score = (TextView) findViewById(R.id.score);
	    goodsIntr = (TextView) findViewById(R.id.goods_intro);
	    subOrder = (TextView) findViewById(R.id.submit_order);
	    
	    //��ȡ��Ʒ���
	    Bundle bundle = getIntent().getExtras();
	    
	    goodsId = bundle.getString("goodsId");
	    goodsName = bundle.getString("goods_name");
	    goodsPrice = bundle.getDouble("goods_price");
	    goodsStore = bundle.getInt("goods_store");
	    
	    System.out.println("���======"+goodsStore);
	    
	    stuId = bundle.getString("stuId");
	    Instantiation();
	    
	    
	    //�ύ�����¼�
	    subOrder.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				
				//��ȡ�µ�ʱ��
				SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//�������ڸ�ʽ
		        System.out.println(df.format(new Date()));// new Date()Ϊ��ȡ��ǰϵͳʱ��
				
				
				
				//���ݶ�����Ϣ
				Bundle toOrdBundle = new Bundle();
				toOrdBundle.putString("goodsId", goodsId);
				toOrdBundle.putString("goods_name", goodsName);
				toOrdBundle.putDouble("goods_price", goodsPrice);
				toOrdBundle.putInt("goods_store", goodsStore);
				toOrdBundle.putString("stuId", stuId);
				toOrdBundle.putString("order_time", df.format(new Date()));
				Intent toOrderPage = new Intent(gDetailActivity.this, OrderActivity.class);
				toOrderPage.putExtras(toOrdBundle);
				
				startActivity(toOrderPage);
				
				finish();
				
			}
		});
	 
	  }
	 
	  public void Instantiation() {
	 
	    //��ʼ��ͼƬ��Դ
	    viewpage_imageList = new ArrayList<ImageView>();
	    
	    //�����ݿ�ȡ������
	    GoodsDetailDao goodsDetailDao = new GoodsDetailDao(this);
	    GoodsDetail goodsDetail = goodsDetailDao.find(goodsId);
	    if (goodsDetail == null) {
			System.out.println("goodsDetailΪ��ֵ");
		}
	    
	    int[] viewpage_images = {goodsDetail.getFirstImg(),goodsDetail.getSecondImg(),goodsDetail.getThirdImg(),goodsDetail.getFourthImg()};
	    //int[] viewpage_images = {R.drawable.codefirst, R.drawable.codetwo, R.drawable.codethree};
	    
	    for (int i : viewpage_images) {
	      // ��ʼ��ͼƬ��Դ
	      ImageView imageView = new ImageView(this);
	      imageView.setBackgroundResource(i);
	      viewpage_imageList.add(imageView);
	 
	      // ���ָʾС��
	      ImageView point = new ImageView(this);
	      LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(15,
	          15);
	      params.rightMargin = 10;
	      params.bottomMargin = 15;
	      point.setLayoutParams(params);
	      point.setBackgroundResource(R.drawable.light_green_point);
	      if (i == viewpage_images[1]) {
	        //Ĭ�Ͼ۽��ڵ�һ��
	        point.setBackgroundResource(R.drawable.green_point);
	        point.setEnabled(true);
	      } else {
	        point.setEnabled(false);
	      }
	 
	      point_detail.addView(point);
	 
	    }
	 
	    //��ҳ�ֲ�
	    CarouselShow carouselShow = new CarouselShow(context, viewpage_imageList);
	    carouselShow.CarouselShow_Info_Detail(this);
	    handler.sendEmptyMessageDelayed(0, 3000);
	    
	    //���ֽ���
	    score.setText(goodsDetail.getScore());
	    goodsIntr.setText(goodsDetail.getGoodsIntro());
	 
	  }
	 
	  private Handler handler = new Handler() {
	    public void handleMessage(Message msg) {
	      // ִ�л�������һ��ҳ��
	      ViewPage_Detail.setCurrentItem(ViewPage_Detail.getCurrentItem() + 1);
	      if (isRunning) {
	        // �ڷ�һ��handler��ʱ
	        handler.sendEmptyMessageDelayed(0, 3000);
	      }
	    }
	  };
	 
	 
	  @Override
	  public void onDestroy() {
	    // ֹͣ����
	    isRunning = false;
	    super.onDestroy();
	  }
	
}
