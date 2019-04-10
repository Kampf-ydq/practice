package com.man.activity;

import com.example.eat.R;
import com.man.dao.UserDao;
import com.man.entity.User;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.text.TextUtils;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class RegistActivity extends Activity {
	
	private EditText account;
	private EditText password;
	private EditText pwdSure;
	private Button registBtn;
	private boolean flag = false;


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.regist);
		
		//��ʼ���ؼ�
		account = (EditText) findViewById(R.id.account);
		password = (EditText) findViewById(R.id.password);
		pwdSure = (EditText) findViewById(R.id.pwd_sure);
		registBtn = (Button) findViewById(R.id.regist);

		
		registBtn.setOnClickListener(regListener);
	}
	
	OnClickListener regListener = new OnClickListener() {
		
		@Override
		public void onClick(View v) {
			if (v.getId() == R.id.regist) {
				
				regist();
				
				//�]�Գɹ���ǰȥ���
				if (flag) {
					Intent intent = new Intent(RegistActivity.this, LoginActivity.class);
					startActivity(intent);
					finish();
				}
				
			}
		}
	};
	
	private static boolean isNumeric(String str){
		for (int i = 0; i < str.length(); i++) {
			if (!Character.isDigit(str.charAt(i))) {
				return false;
			}
		}
		return true;
	}
	
	private void regist(){
		String acc = account.getText().toString().trim();
		String pd = password.getText().toString().trim();
		String pd_sure = pwdSure.getText().toString().trim();
		
		//�ж������Ƿ�Ϊ��
		if (TextUtils.isEmpty(acc) || TextUtils.isEmpty(pd) || TextUtils.isEmpty(pd_sure)) {
			Toast.makeText(RegistActivity.this, "����ȷ��дѧ�ź�����", 0).show();
			return;
		}
		
		//�ж������Ƿ�Ϸ�
		if (acc.length() != 9 || !isNumeric(acc)) {
			Toast.makeText(RegistActivity.this, "ѧ�Ÿ�ʽ����", 0).show();
			return;
		}
		if (pd.length() != 6 || !isNumeric(pd)) {
			Toast.makeText(RegistActivity.this, "�����ʽ����", 0).show();
			return;
		}
		if (!pd.equals(pd_sure)) {
			Toast.makeText(RegistActivity.this, "������������벻һ��", 0).show();
			return;
		}
		
		//�жϸ�ѧ���Ƿ���ע��
		UserDao findUserDao = new UserDao(RegistActivity.this);
		User dbUser = findUserDao.find(acc);
		
		//һ��Ҫע���Д���ҽY���Ƿ���
		if (dbUser != null && acc.equals(dbUser.getAccount())) {
			Toast.makeText(RegistActivity.this, "��ѧ����ע�ᣬ��ǰ����¼", 0).show();
			return;
		}
		
	    //һ�кϷ������ע��
		User user = new User(acc, pd);
		System.out.println(user);
		UserDao addUserDao = new UserDao(RegistActivity.this);
		addUserDao.add(user);
		flag = true;
		Toast.makeText(RegistActivity.this, "ע��ɹ�", 0).show();
	}

}
