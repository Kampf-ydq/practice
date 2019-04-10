package com.man.activity;

import com.example.eat.R;
import com.man.dao.UserDao;
import com.man.entity.User;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.view.Window;
import android.view.View.OnClickListener;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class LoginActivity extends Activity {
	
	private boolean isLoginSuccess = true;//��¼�Ƿ�ɹ�
	
	private EditText stuId;
	private EditText pwd;
	private CheckBox rem;
	private Button loginBtn;
	private TextView regist;
	private TextView forgetPwd;

	
	private SharedPreferences sp;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		//ȥ��������
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		
		//����ȫ��
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
		
		setContentView(R.layout.login);
		
		//��ʼ���ؼ�
		stuId = (EditText)findViewById(R.id.std_id);
		pwd = (EditText)findViewById(R.id.pwd);
		rem = (CheckBox)findViewById(R.id.remember);
		loginBtn = (Button)findViewById(R.id.login);
		regist = (TextView) findViewById(R.id.regist);
		forgetPwd = (TextView) findViewById(R.id.forget_pwd);
		
		sp = getSharedPreferences("loginStatu", 0);
		
		
		boolean isRemember = sp.getBoolean("isChecked", false);//Ĭ��ֵΪfalse
		
		//��ѡ�˼�ס����
		if (isRemember) {
			
			//����,�ҵ���number��password��ֵ�ͷ��ظ�ֵ�����򷵻�Ĭ��ֵ
			String num = sp.getString("number", "");
			String passwd = sp.getString("password", "");
			
			stuId.setText(num);
			pwd.setText(passwd);
			rem.setChecked(true);
		}
		
		//����OnClickListener()�������ò�ͬ��ť�µļ����¼�
		loginBtn.setOnClickListener(mListener);
		regist.setOnClickListener(mListener);
		forgetPwd.setOnClickListener(mListener);
		
	}

	OnClickListener mListener = new OnClickListener() {//��ͬ��ť�µļ����¼�
		
		@Override
		public void onClick(View v) {
			switch (v.getId()) {
			case R.id.login:	//��¼ҳ��ĵ�¼��ť
				login();
				if (isLoginSuccess) {
					finish();//����
				}
				break;
			case R.id.regist:	//��¼ҳ���ע��ѡ��
				Intent toRegist = new Intent();
				toRegist.setClass(LoginActivity.this, RegistActivity.class);
				startActivity(toRegist);
				finish();
				break;	
			case R.id.forget_pwd:	//��¼ҳ����һ�����ѡ��
				Intent toFindPwd = new Intent();
				toFindPwd.setClass(LoginActivity.this, FindPwdActivity.class);
				startActivity(toFindPwd);
				finish();
				break;
			default:
				break;
			}
			
		}
	};
	
	private void login(){
		//��ȡ����
		String studentId = stuId.getText().toString().trim();
		String password = pwd.getText().toString().trim();
		Editor editor = sp.edit();
		
		//�ж������Ƿ�Ϸ�
		if (TextUtils.isEmpty(studentId) || TextUtils.isEmpty(password)) {
			Toast.makeText(LoginActivity.this, "������ѧ�ź�����", Toast.LENGTH_SHORT).show();
			return;
		}
		
		//�ж�ѧ�š������Ƿ���ȷ
		UserDao finUserDao = new UserDao(LoginActivity.this);
		User dbUser = finUserDao.find(studentId);
		
		if (dbUser != null && studentId.equals(dbUser.getAccount()) && password.equals(dbUser.getPassword())) {//��¼�ɹ�
			//�ж��Ƿ�ѡ��checkBox
			if (rem.isChecked()) {
				//��������(ʹ��SharedPreference)
				editor.putString("number", studentId);
				editor.putString("password", password);
				editor.putBoolean("isChecked", true);
			}else {
				editor.clear();
			}
			editor.commit();
			
			Toast.makeText(LoginActivity.this, "��¼�ɹ�", Toast.LENGTH_SHORT).show();
			
			//������ҳ
			Intent toHome = new Intent(LoginActivity.this, HomeActivity.class);
			
			//����intent��ѧ�Ŵ���ȥ
			toHome.putExtra("stu_id", dbUser.getAccount());
			
			startActivity(toHome);
		}else {
			Toast.makeText(LoginActivity.this, "ѧ�Ż��������", Toast.LENGTH_SHORT).show();
			isLoginSuccess = false;
		}	
	}
	
}
