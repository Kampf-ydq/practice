package com.man.activity;

import com.example.eat.R;
import com.man.dao.UserDao;
import com.man.entity.User;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.TextView;

public class LookAddress extends Activity {
	
	private TextView name;
	private TextView tel;
	private TextView address;
	private TextView editAdd;
	private String acc;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		
		setContentView(R.layout.address_infor);
		
		Intent intent = getIntent();
		acc = intent.getStringExtra("stu_id");
		
		//��ʼ���ؼ�
		name = (TextView) findViewById(R.id.name_infor);
		tel = (TextView) findViewById(R.id.tel_infor);
		address = (TextView) findViewById(R.id.add_infor);
		editAdd = (TextView) findViewById(R.id.edit);
		
		//��ʾϵͳ�����Ĭ��ֵ
		UserDao userDao = new UserDao(LookAddress.this);
		User dbUser = userDao.find(acc);
		name.setText(dbUser.getUserName());
		tel.setText(dbUser.getTelPhone());
		address.setText(dbUser.getAddress());
		
		editAdd.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				//�޸ĵ�ַ��Ϣ
				Intent toEditAdd = new Intent(LookAddress.this, EditAddress.class);
				toEditAdd.putExtra("stu_id", acc);
				startActivityForResult(toEditAdd, 1);	
			}
		});
	}
	
	
	//��EditActivity�����ٺ������������
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		switch (requestCode) {
		case 1:
			if (resultCode == RESULT_OK) {
				String n = data.getStringExtra("ret_name");
				String t = data.getStringExtra("ret_tel");
				String a = data.getStringExtra("ret_add");
				
				name.setText(n);
				tel.setText(t);
				address.setText(a);
				
			}
			break;

		default:
			break;
		}
	}

}
