package com.man.activity;

import java.util.List;

import com.Utils.GetOrderId;
import com.Utils.PayWayDialog;
import com.example.eat.R;
import com.man.dao.GoodsDao;
import com.man.dao.UserDao;
import com.man.entity.User;

import android.app.Activity;
import android.app.Dialog;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.view.WindowManager;
import android.widget.AbsListView;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;


public class OrderActivity extends Activity {
	
	private TextView goodsName;
	private TextView name;
	private TextView tel;
	private TextView add;
	private TextView orderNum;
	private TextView orderTime;
	
	private String stuId;
	private String goodsId;
	
	private TextView pay;
	
	private double smMoney;//�û����
	private double goodsMoney;//��Ʒ�۸�/ÿ����
	private int goodsStroe;//��Ʒ���
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		
		setContentView(R.layout.order);
		
		//��������
		Bundle bundle = getIntent().getExtras();
		
		String ordTime = bundle.getString("order_time");
		String gname = bundle.getString("goods_name");
		stuId = bundle.getString("stuId");
		goodsId = bundle.getString("goodsId");
		goodsMoney = bundle.getDouble("goods_price");
		goodsStroe = bundle.getInt("goods_store");
		
		 System.out.println("���======"+goodsStroe);
		
		//��ʼ���ؼ�
		goodsName = (TextView) findViewById(R.id.goods_name);
		name = (TextView) findViewById(R.id.user_name);
		tel = (TextView) findViewById(R.id.telephone);
		add = (TextView) findViewById(R.id.address);
		orderNum = (TextView) findViewById(R.id.order_number);
		orderTime = (TextView) findViewById(R.id.order_time);
		pay = (TextView) findViewById(R.id.pay);
		
		UserDao userDao = new UserDao(this);
		User user = userDao.find(stuId);
		smMoney = user.getMoney();
		
		//��ʾ������Ϣ
		goodsName.setText(gname);
		name.setText(user.getUserName());
		tel.setText(user.getTelPhone());
		add.setText(user.getAddress());
		orderNum.setText(GetOrderId.produceOrderId());
		orderTime.setText(ordTime);
		
		pay.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				//�ж�����Ƿ��㹻
				if (smMoney < goodsMoney) {
					Toast.makeText(OrderActivity.this, "���㣬��ȥ׬ȡѧϰ��", 0).show();
					return;
				}
				initDialog(OrderActivity.this);
				
				//�������ݿ��t_user���ֵ,t_goods��storeNumֵ
				updateDb(OrderActivity.this);
				
			}
		});
	
	}
	
	//��ʼ���Զ���Dialog
	private void initDialog(Context context){
		PayWayDialog payWayDialog = new PayWayDialog(context, R.style.recharge_pay_dialog,
		              String.valueOf(smMoney), String.valueOf(goodsMoney), new OnClickListener() {
														
						@Override
						public void onClick(View v) {
							Toast.makeText(OrderActivity.this, "����֧��"+goodsMoney+"ѧϰ��", 0).show();
							Handler handler = new Handler();
							handler.sendEmptyMessageDelayed(0, 2000);
							finish();
						}
					});
		payWayDialog.show();
	}
	
	//�������ݿ�
	private void updateDb(Context context){
		UserDao userDao = new UserDao(context);
		userDao.updateMoney(smMoney-goodsMoney, stuId);
		
		GoodsDao goodsDao = new GoodsDao(context);
		int gs = goodsStroe - 1;//һ�ι涨��һ��
		goodsDao.update(gs, goodsId);
	}
	

}















