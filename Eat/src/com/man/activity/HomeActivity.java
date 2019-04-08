package com.man.activity;

import java.util.ArrayList;
import java.util.List;

import com.example.eat.R;
import com.man.dao.GoodsDao;
import com.man.entity.Goods;
import com.man.adapter.GoodsAdapter;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

public class HomeActivity extends Activity {
	
	private List<Goods> goodsList = new ArrayList<Goods>();
	private ListView listView;
	private String userAcc;
	
	private Button learn;
	private Button eat;
	private Button personal;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		
		setContentView(R.layout.home_layout);
		
		//�õ�����HomeActivity����ͼ����
		Intent intent = getIntent();
		userAcc = intent.getStringExtra("stu_id");
		
		//System.out.println("ѧ�ţ� ====== "+userAcc);
		
		learn = (Button) findViewById(R.id.study_btn);
		eat = (Button) findViewById(R.id.eat_btn);
		personal = (Button) findViewById(R.id.personal_btn);
		
		//�����ݿ�ȡ������
		GoodsDao goodsDao = new GoodsDao(HomeActivity.this);
		goodsList = goodsDao.getAll();
		
		if (goodsList == null) {
			Log.e("SQLite", "���ݿ�t_goods��������");
			return;
		}
		//ΪListView���ÿ���������������
		GoodsAdapter adapter = new GoodsAdapter(HomeActivity.this, R.layout.goods_item_layout, goodsList);
		listView = (ListView) findViewById(R.id.show_goods);
		listView.setAdapter(adapter);
		
		personal.setOnClickListener(hListener);
		learn.setOnClickListener(hListener);
		
		listView.setOnItemClickListener(new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view,
					int position, long id) {
				Goods goods = goodsList.get(position);
				
				//��������Bundle���ݰ�
				Bundle bundle = new Bundle();
				bundle.putString("goodsId", goods.getGoodsId());
				bundle.putString("goods_name", goods.getGoodsName());
				bundle.putDouble("goods_price", goods.getPrice());
				bundle.putInt("goods_store", goods.getStoreNum());
				bundle.putString("stuId", userAcc);
				Intent toDetailPage = new Intent(HomeActivity.this, gDetailActivity.class);
				toDetailPage.putExtras(bundle);
				
				startActivity(toDetailPage);
				
				
			}
			
		});
		
	}
	
	OnClickListener hListener = new OnClickListener() {
		
		@Override
		public void onClick(View v) {
			switch (v.getId()) {
			case R.id.personal_btn:
				Intent toPersonal = new Intent(HomeActivity.this, PersonalActivity.class);
				toPersonal.putExtra("stu_id", userAcc);
				startActivity(toPersonal);
				break;
				
			case R.id.study_btn:
				Intent toLearn = new Intent(HomeActivity.this, LearnAcitity.class);
				toLearn.putExtra("stu_id", userAcc);
				startActivity(toLearn);
				break;

			default:
				break;
			}
			
		}
	};
		
	
	//��������HomeActivity�������onRestart()ˢ��ҳ������
	protected void onRestart() {
		super.onRestart();
		GoodsDao goodsDao = new GoodsDao(HomeActivity.this);
		goodsList = goodsDao.getAll();
		
		if (goodsList == null) {
			Log.e("SQLite", "���ݿ�t_goods��������");
			return;
		}
		//ΪListView���ÿ���������������
		GoodsAdapter adapter = new GoodsAdapter(HomeActivity.this, R.layout.goods_item_layout, goodsList);
		listView = (ListView) findViewById(R.id.show_goods);
		listView.setAdapter(adapter);
	};
}
