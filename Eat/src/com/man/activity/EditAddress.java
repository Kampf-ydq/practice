package com.man.activity;

import com.example.eat.R;
import com.man.dao.UserDao;
import com.man.entity.User;

import android.R.string;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.view.Window;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class EditAddress extends Activity {
	
	private EditText name;
	private EditText tel;
	private EditText address;
	private String acc;
	private Button saveBtn;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		
		setContentView(R.layout.edit_address);
		
		//��ȡ�˺�
		Intent intent = getIntent();
		acc = intent.getStringExtra("stu_id");
		
		//��ʼ���ؼ�
		name = (EditText) findViewById(R.id.edit_name);
		tel = (EditText) findViewById(R.id.edit_tel);
		address = (EditText) findViewById(R.id.edit_add);
		saveBtn = (Button) findViewById(R.id.save_edit_add);
		
		
		//�����޸�ֵ
		saveBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				String userName = name.getText().toString().trim();
				String telPhone = tel.getText().toString().trim();
				String add = address.getText().toString().trim();
				
				if (TextUtils.isEmpty(userName) || TextUtils.isEmpty(telPhone) || TextUtils.isEmpty(add)) {
					Toast.makeText(EditAddress.this, "��������ȷ����Ϣ", 0).show();
					return;
				}
				
				//�������ݿ���Ϣ
				UserDao userDao = new UserDao(EditAddress.this);
				userDao.updateAddress(userName, telPhone, add, acc);
				Toast.makeText(EditAddress.this, "�޸ĳɹ�", 0).show();
				
				//���ص�ַ��ʾҳ��,�������޸ĺ������
				Intent toLookAdd = new Intent();
				toLookAdd.putExtra("ret_name", userName);
				toLookAdd.putExtra("ret_tel", telPhone);
				toLookAdd.putExtra("ret_add", add);
				setResult(RESULT_OK, toLookAdd);
				finish();//���ٻ
			}
		});
	}

}
